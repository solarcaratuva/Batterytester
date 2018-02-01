clear;      %clear workspace
close all;  %close all figures;
clc;        %clear console

filename = 'data/data.csv';

M = csvread(filename)

disp(M);

%This is the part we will use when we get an SD Card text file read in
%{
Time = Matrix(:,1);
Voltage = Matrix(:,2)*(2.5/4095);
i = 5;
E = i.*(cumtrapz(Time, Voltage)); %trapezoidal integration
E_final = E(end);
plot(Time, E)
MatrixC = Matrix(:,3);
plot(Time,Voltage,'y-',Time,MatrixC,'go')
%}