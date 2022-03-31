import numpy as np
import pandas as pd
import matplotlib.pyplot as plt

"""
关于类的封装的说明   这个类的使用需要用户传入数据集，同时确保需要预测的值在最后一列

"""
class Regression():
    def __init__(self):
        self.ws = []     # 获得最小二乘法的系数
        self.new_theat = []  # 获得代价函数的系数
        self.rms = []   # 获得均方误差
        self.cost = []  # 获得损失值
        self.pre = []

    def standranger(self, x_arr, y_arr):  # 最小二乘法来获取theat的值
        x_mat = np.mat(x_arr)  # 将特征变量x数据源转为矩阵
        y_mat = np.mat(y_arr)  # 将y值转化为矩阵的形式
        x_is = x_mat.T * x_mat
        if np.linalg.det(x_is) == 0.0:
            print("矩阵是奇异矩阵")
            return 0
        ws = x_is.I * (x_mat.T * y_mat)
        self.ws = ws
        return ws

    def cost_function(self, X, y, theat):
        inner = np.power((X @ theat - y), 2)
        return np.sum(inner) / (2 * len(X))

    def gradint_descent(self, X, y, theat, altha, iters):
        costs = []
        for item in range(iters):
            theat = theat - (X.T @ (X @ theat - y)) * altha / len(X)
            cost = self.cost_function(X, y, theat)
            costs.append(cost)
        self.new_theat = theat
        self.cost = costs
        return theat, costs

    def rmse(self, x_text, y_text):
        y_pre = x_text @ self.new_theat
        self.pre = y_pre
        inner = np.sum(np.power(y_text - y_pre, 2)) / len(y_text)
        self.rms = inner
        return np.sqrt(inner)


def StandardScaler(data):   # z-zeros标准化处理
    columns = data.columns
    for item in columns:
        data[item]=(data[item]-data[item].mean())/data[item].std()


def picture_cost(iters,cost):   # 绘制代价函数的曲线
    fig,ax = plt.subplots(figsize=(12,8))
    ax.plot(np.arange(iters),cost)
    ax.set_xlabel("iters")
    ax.set_ylabel("cost")
    ax.set_title("Linner Cost Function")
    plt.show()

def main():
    house_df = pd.read_fwf('./housing.data',
                           names=['CRIM', 'ZN', 'INDUS', 'CHAS', 'NOX', 'RM', 'AGE', 'DIS', 'RAD', 'TAX', 'PTRATIO',
                                  'B', 'LSTAT', 'MEDV'])
    house_df = house_df.drop(labels=['CHAS', 'NOX', 'RM', 'ZN'], axis=1)  # 过滤数据
    StandardScaler(house_df)  # 标准化处理数据
    house_df.insert(0, 'ones', 1)  # 补充全1行
    """
    获取测试集和验证集....
    """
    row = int(house_df.shape[0] - house_df.shape[0] * 0.1)
    x_train = house_df.iloc[:row, :-2].values
    y_train = house_df.iloc[:row, -2:-1].values
    x_text = house_df.iloc[row:, :-2].values
    y_text = house_df.iloc[row:, -1].values
    theat = np.zeros((x_train.shape[1], 1))
    # 调用类对象
    pre = Regression()
    ites = 1000
    altha = 0.000007
    pre.gradint_descent(x_train, y_train, theat, altha, ites)  # 梯度下降
    pre.standranger(x_train, y_train)   # 最小二乘法
    print("---------梯度下降---------------")
    print(pre.new_theat)
    print("---------最小二乘法-------------")
    print(pre.ws)
    rms = pre.rmse(x_text, y_text)  # 均方误差
    print("---------均方误差---------------")
    print(rms)
    print("----------y的预测值------------")
    print(pre.pre)  # 获得预测值
    picture_cost(ites, pre.cost)  # 绘制损失函数的曲线


if __name__ == '__main__':
    main()
    print("拟合完成")