using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace NoaNeuralNet
{
    [Serializable]
    public struct NetLayer
    {
        public double[] layer;
        public ActivationFunction activationFunction;
        public Action<double[]> activationFunc;   //激活函数
    }
}
