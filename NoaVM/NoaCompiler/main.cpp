#include <stdio.h>
#include <stdlib.h>

// 词法单元类型枚举定义
typedef enum {
    NUMBER,  // 数字
    ADD      // 加号
} TokenType;

// 词法单元结构体定义
typedef struct {
    TokenType type;
    int value;
} Token;

// 全局变量
Token currentToken;
int position = 0;

// 从输入的字符串中获取下一个词法单元
Token getNextToken(char * expression) {
    Token token;
    
    // 跳过空格和空白字符
    while (expression[position] == ' ' || expression[position] == '\n') {
        position++;
    }

    // 到达字符串末尾
    if (expression[position] == ';') {
        token.type = ADD; // 当输入为空时，直接返回 ADD 作为结束标志
        return token;
    }

    // 处理数字词法单元
    if (expression[position] >= '0' && expression[position] <= '9') {
        token.type = NUMBER;
        token.value = expression[position] - '0';
        position++;
        return token;
    }

    // 处理加号词法单元
    if (expression[position] == '+') {
        token.type = ADD;
        position++;
        return token;
    }

    // 不支持的词法单元，出错处理
    printf("Error: Invalid token\n");
    exit(1);
}

// 抽象语法树节点结构体定义
typedef struct ASTNode{
    Token token;
    struct ASTNode* left;
    struct ASTNode* right;
} ASTNode;

// 创建一个抽象语法树节点
ASTNode* createNode(Token token) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->token = token;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// 语法分析器
ASTNode* parseExpression(char * expression) {
    Token token = getNextToken(expression);
    ASTNode* node = createNode(token);

    // 处理递归下降解析
    if (node->token.type == NUMBER) {
        return node;
    }
    else if (node->token.type == ADD) {
        node->left = parseExpression(expression);
        node->right = parseExpression(expression);
        return node;
    }
    else {
        printf("Error: Invalid syntax\n");
        exit(1);
    }
}

// 生成汇编代码
void generateCode(ASTNode* node) {
    if (node->token.type == NUMBER) {
        printf("LOAD %d\n", node->token.value);
    }
    else if (node->token.type == ADD) {
        generateCode(node->left);
        generateCode(node->right);
        printf("ADD\n");
    }
}

int main() {
    // 读取输入的表达式
    char expression[] = "2 + 3 + 4 + 5;";

    // 初始化全局变量
    position = 0;

    // 解析表达式并生成汇编代码
    ASTNode* root = parseExpression(expression);
    generateCode(root);

    return 0;
}