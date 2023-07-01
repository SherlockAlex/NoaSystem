using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NoaNeuralNet
{

    public abstract class NeuralNet
    {

        public NeuralNetGene netBehaviourSO;

        public NeuralNet(int inputCount,int outputCount) 
        {
            netBehaviourSO = new NeuralNetGene(inputCount,outputCount);
            netBehaviourSO.layers.Clear();
            //添加层
        }

        public void AddLayer(double[] layerNodes,ActivationFunction activationFunction)
        {
            netBehaviourSO.AddLayer(layerNodes,activationFunction);
        }

        public void AddOutLayer(int outputSize, ActivationFunction activationFunction)
        {
            netBehaviourSO.SetOutputLayer(outputSize, activationFunction);
        }

        public double[] Compute(double[] input)
        {
            return netBehaviourSO.Compute(input);
        }

    }

    public class NeuralNetGene
    {
        public float fitness = 0;                               //模型得分

        public double[] gene;                                   //权重偏差，即基因
        public List<NetLayer> layers = new List<NetLayer>();    //保存神经网络的层
        int inputCount = 0;
        int outputCount = 0;
        NetLayer output;

        public void AddLayer(double[] layer, ActivationFunction activationFunction)
        {
            NetLayer netLayer;
            netLayer.layer = layer;
            netLayer.activationFunction = activationFunction;
            netLayer.activationFunc = NetMath.GetActivationFunc(activationFunction);
            layers.Add(netLayer);
        }

        public void SetOutputLayer(int outputCount, ActivationFunction activationFunction)
        {
            output.layer = new double[outputCount];
            output.activationFunc = NetMath.GetActivationFunc(activationFunction);
        }

        public NeuralNetGene(int inputCount,int outputCount)
        {
            this.InitNet(inputCount, outputCount);
        }

        public void InitNet(int inputCount, int outputCount)
        {
            //先执行完Addlayer才行
            //初始化个体
            //计算权重数量

            this.inputCount = inputCount;
            this.outputCount = outputCount;

            int weightCount = 0;
            int layerCount = layers.Count;

            weightCount += inputCount * layers[0].layer.Length + layers[0].layer.Length;
            for (int i = 0; i < layerCount - 1; i++)
            {
                weightCount += layers[i].layer.Length * layers[i + 1].layer.Length + layers[i + 1].layer.Length;
            }
            weightCount += layers[layerCount - 1].layer.Length * outputCount + outputCount;

            //Debug.Log($"Gene Count = {weightCount}");

            //建立权重数组
            gene = new double[weightCount];

        }

        public void InitGene(float min, float max)
        {
            //初始化基因
            for (int i = 0; i < gene.Length; i++)
            {

                gene[i] = NetMath.RandomRange(min, max);
            }
        }

        public double[] Compute(double[] input)
        {
            //根据输入计算输出值
            int startPos = 0;
            int layerCount = layers.Count;
            NetMath.Compute(input, layers[0].layer, gene, startPos);
            layers[0].activationFunc.Invoke(layers[0].layer);
            startPos = layers[0].layer.Length * input.Length + layers[0].layer.Length;

            for (int i = 0; i < layerCount - 1; i++)
            {
                NetMath.Compute(layers[i].layer, layers[i + 1].layer, gene, startPos);
                layers[i + 1].activationFunc.Invoke(layers[i + 1].layer);
                startPos = layers[i + 1].layer.Length * layers[i].layer.Length + layers[i + 1].layer.Length;
            }

            NetMath.Compute(layers[layerCount - 1].layer, output.layer, gene, startPos);
            output.activationFunc.Invoke(output.layer);

            return output.layer;

        }

        /// <summary>
        /// 实现对象之间的交配
        /// </summary>
        /// <param name="father"></param>
        /// <param name="mother"></param>
        public void Evolute(NeuralNetGene father, NeuralNetGene mother)
        {
            //进化
            //规则是随机选取father一段基因，进行替换
            //1/20的几率下某一段基因发生变异

            //单点杂交
            int pox = NetMath.RandomRange(3, gene.Length);
            for (int i = 0; i < pox; i++)
            {
                gene[i] = father.gene[i];
            }
            for (int i = pox; i < gene.Length; i++)
            {
                gene[i] = mother.gene[i];
            }

            int p = NetMath.RandomRange(0, 50);
            if (p == 5)
            {
                //发生基因突变
                int index = NetMath.RandomRange(0, gene.Length);
                gene[index] = NetMath.RandomRange(-1.0f, 1);
            }
            if (p == 7 || p == 14 || (p == 5 && p == 10))
            {
                //发生基因交换
                int i = NetMath.RandomRange(0, gene.Length);
                int j = NetMath.RandomRange(0, gene.Length);
                double t = gene[i];
                gene[i] = gene[j];
                gene[j] = t;
            }


        }

        /// <summary>
        /// 拷贝对象的基因到本体
        /// </summary>
        /// <param name="netBehaviourSO"></param>

        public void CopyData(NeuralNetGene netBehaviourSO)
        {
            //拷贝数据
            if (netBehaviourSO == this)
            {
                return;
            }

            for (int i = 0; i < gene.Length; i++)
            {
                gene[i] = netBehaviourSO.gene[i];
            }



        }

        public void AddFitness(float value)
        {
            fitness += value;
        }

        public void RemoveFitness(float value)
        {
            fitness -= value;
        }

    }
}
