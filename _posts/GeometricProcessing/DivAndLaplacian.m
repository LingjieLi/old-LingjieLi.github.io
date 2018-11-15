clear;clc;close all
[X,Y] = meshgrid(-2:.2:2);        % ������������X��Y
Z = X.*exp(-X.^2 - Y.^2)+0.5;         % ��������㴦�����ϵ�Zֵ
[DX,DY] = gradient(Z,0.2,0.2);    % ���������ϸ��㴦���ݶ�
 
figure;
surfc(X,Y,Z);                       %���ƺ���
hold on
q=quiver(X,Y,DX,DY,'k') ;               % �����ݶȳ�
q.Color='black';
q.LineWidth=0.9;
q.MaxHeadSize=2.5

