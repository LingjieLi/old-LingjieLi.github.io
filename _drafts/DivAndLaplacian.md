clear;clc;close all
[X,Y] = meshgrid(-2:.2:2);        % 产生网格数据X和Y
Z = X.*exp(-X.^2 - Y.^2)+0.5;         % 计算网格点处曲面上的Z值
[DX,DY] = gradient(Z,0.2,0.2);    % 计算曲面上各点处的梯度
 
figure;
surfc(X,Y,Z);                       %绘制函数
hold on
q=quiver(X,Y,DX,DY,'k') ;               % 绘制梯度场
q.Color='black';
q.LineWidth=0.9;
q.MaxHeadSize=2.5

