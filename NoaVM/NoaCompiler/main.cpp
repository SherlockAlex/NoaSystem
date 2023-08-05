#include <stdio.h>
#include <stdlib.h>

// �ʷ���Ԫ����ö�ٶ���
typedef enum {
    NUMBER,  // ����
    ADD      // �Ӻ�
} TokenType;

// �ʷ���Ԫ�ṹ�嶨��
typedef struct {
    TokenType type;
    int value;
} Token;

// ȫ�ֱ���
Token currentToken;
int position = 0;

// ��������ַ����л�ȡ��һ���ʷ���Ԫ
Token getNextToken(char * expression) {
    Token token;
    
    // �����ո�Ϳհ��ַ�
    while (expression[position] == ' ' || expression[position] == '\n') {
        position++;
    }

    // �����ַ���ĩβ
    if (expression[position] == ';') {
        token.type = ADD; // ������Ϊ��ʱ��ֱ�ӷ��� ADD ��Ϊ������־
        return token;
    }

    // �������ִʷ���Ԫ
    if (expression[position] >= '0' && expression[position] <= '9') {
        token.type = NUMBER;
        token.value = expression[position] - '0';
        position++;
        return token;
    }

    // ����ӺŴʷ���Ԫ
    if (expression[position] == '+') {
        token.type = ADD;
        position++;
        return token;
    }

    // ��֧�ֵĴʷ���Ԫ��������
    printf("Error: Invalid token\n");
    exit(1);
}

// �����﷨���ڵ�ṹ�嶨��
typedef struct ASTNode{
    Token token;
    struct ASTNode* left;
    struct ASTNode* right;
} ASTNode;

// ����һ�������﷨���ڵ�
ASTNode* createNode(Token token) {
    ASTNode* node = (ASTNode*)malloc(sizeof(ASTNode));
    node->token = token;
    node->left = NULL;
    node->right = NULL;
    return node;
}

// �﷨������
ASTNode* parseExpression(char * expression) {
    Token token = getNextToken(expression);
    ASTNode* node = createNode(token);

    // ����ݹ��½�����
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

// ���ɻ�����
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
    // ��ȡ����ı��ʽ
    char expression[] = "2 + 3 + 4 + 5;";

    // ��ʼ��ȫ�ֱ���
    position = 0;

    // �������ʽ�����ɻ�����
    ASTNode* root = parseExpression(expression);
    generateCode(root);

    return 0;
}