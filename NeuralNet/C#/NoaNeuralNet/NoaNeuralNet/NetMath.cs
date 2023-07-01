namespace NoaNeuralNet
{
    public enum ActivationFunction
    {
        None = 0,
        Sigmoid = 1,
        Tanh = 2,
        ReLU = 3,
    }

    public struct NetMath
    {

        const double pi = 3.1415926;
        const double halfPI = pi / 2;

        static Random random = new Random();

        static double relu(double x)
        {
            if (x > 0)
            {
                return x;
            }
            return 0;
        }

        static double sigmoid(double x)
        {
            return (1 / (1 + System.Math.Exp(-x)));
        }

        static double exp(double x)
        {
            return System.Math.Exp(x);
        }

        static double tanh(double x)
        {
            return (exp(x) - exp(-x)) / (exp(x) + exp(-x));
        }

        static double[,] weightBuffer = new double[200, 200];       //缓冲区
        static double[] biasBuffer = new double[200];               //缓冲区

        //神经网络的计算
        public static void Compute(
            double[] input,     //输入
            double[] output,    //输出
            double[] gene,
            int geneStartIndex  //参与计算的基因其实位置
            )
        {
            //一般来说，权重=输出*输入
            //偏差=输出，所以要用到的数量=输出*输入+输出

            int outCount = output.Length;
            int inputCount = input.Length;

            for (int i = 0; i < outCount; i++)
            {
                output[i] = 0;
            }

            int k = 0;
            k = geneStartIndex;
            //缓冲权重
            for (int i = 0; i < outCount; i++)
            {
                for (int j = 0; j < inputCount; j++)
                {
                    weightBuffer[i, j] = gene[k];
                    k++;
                }
            }
            //对偏差进行缓冲
            k = geneStartIndex + (outCount * inputCount);
            for (int i = 0; i < outCount; i++)
            {
                biasBuffer[i] = gene[k];
                k++;
            }


            for (int i = 0; i < outCount; i++)
            {

                for (int j = 0; j < inputCount; j++)
                {
                    output[i] += (weightBuffer[i, j] * input[j]);
                }
                output[i] += biasBuffer[i];
            }
        }



        public static void Compute(
            List<double> input,     //输入
            List<double> output,    //输出
            List<List<double>> w,   //权值
            List<double> b          //偏差
            )
        {

            for (int i = 0; i < output.Count; i++)
            {
                output[i] = 0;
            }

            for (int i = 0; i < output.Count; i++)
            {

                for (int j = 0; j < input.Count; j++)
                {
                    output[i] += (w[i][j] * input[j]);
                }
                output[i] += b[i];
            }
        }

        public static void Compute(
            double[] input,     //输入
            double[] output,    //输出
            List<List<double>> w,   //权值
            List<double> b          //偏差
            )
        {
            for (int i = 0; i < output.Length; i++)
            {
                output[i] = 0;
            }

            for (int i = 0; i < output.Length; i++)
            {
                output[i] = 0;
                for (int j = 0; j < input.Length; j++)
                {
                    output[i] += (w[i][j] * input[j]);
                }
                output[i] += b[i];
            }
        }

        public static void ReLU(List<double> vector)
        {
            /*激活函数*/
            for (int i = 0; i < vector.Count; i++)
            {
                vector[i] = relu(vector[i]);
            }
        }

        public static void ReLU(double[] vector)
        {
            /*激活函数*/
            for (int i = 0; i < vector.Length; i++)
            {
                vector[i] = relu(vector[i]);
            }
        }


        public static void Sigmoid(List<double> vector)
        {
            /*激活函数*/
            for (int i = 0; i < vector.Count; i++)
            {
                vector[i] = sigmoid(vector[i]);
            }
        }

        public static void Sigmoid(double[] vector)
        {
            /*激活函数*/
            for (int i = 0; i < vector.Length; i++)
            {
                vector[i] = sigmoid(vector[i]);
            }
        }

        public static void Tanh(List<double> vector)
        {
            for (int i = 0; i < vector.Count; i++)
            {
                vector[i] = tanh(vector[i]);
            }
        }

        public static void Tanh(double[] vector)
        {
            for (int i = 0; i < vector.Length; i++)
            {
                vector[i] = tanh(vector[i]);
            }
        }

        public static double Loss(List<double> output, List<double> t)
        {
            //计算损失函数
            double loss = 0;
            int count = output.Count;
            for (int i = 0; i < count; i++)
            {
                loss = loss + (output[i] - t[i]) * (output[i] - t[i]);
            }

            return loss;

        }

        public static Action<double[]> GetActivationFunc(ActivationFunction activationFunction)
        {
            switch (activationFunction)
            {
                case ActivationFunction.None:
                    //netLayer.activationFunc = null;
                    return null;
                case ActivationFunction.Sigmoid:
                    //netLayer.activationFunc = NetMath.Sigmoid;
                    return Sigmoid;
                case ActivationFunction.Tanh:
                    //netLayer.activationFunc = NetMath.Tanh;
                    return Tanh;
                case ActivationFunction.ReLU:
                    return ReLU;
                //netLayer.activationFunc = NetMath.ReLU;
                default:
                    //netLayer.activationFunc = NetMath.Tanh;
                    return null;
            }
        }

        public static double RandomRange(double min,double max)
        {
            return random.NextDouble() * (max - min) + min;
        }

        public static int RandomRange(int min,int max)
        {
            return random.Next(min,max);
        }

    }
}