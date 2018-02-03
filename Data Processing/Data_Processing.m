clear;      %clear workspace
close all;  %close all figures;
clc;        %clear console

%{
filename = 'data/data.csv';

M = csvread(filename)

disp(M);

%}

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


%Function: to accurately parse CSV data obtained from the SD card 

%Matrix for the voltages, current, and temperature where each column is a
%seperate battery 

filename = 'data_processing_test.csv'; %insert file name  
num_batteries = 6; 

input_file = fopen(filename,'r');
if (input_file ~= -1)
     all_data=csvread(filename);
     [timeentries, columns] = size(all_data);
     voltage_data = zeros(timeentries, num_batteries);
 
    
    for n=1:1:num_batteries
        voltage_data(:,n) = all_data(:,n);
    end 
end
