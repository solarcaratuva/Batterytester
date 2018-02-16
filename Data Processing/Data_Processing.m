clear;      %clear workspace
close all;  %close all figures;
clc;        %clear console

filename = 'batch';
letters = ['A','B','C','D','E','F','G','H','I','J','K','L','M','N'];

v = [2:3:91];
c = [3:3:91];
capacity_matrix = [];
for letta = 1:length(letters) %Iterates through batch names of A-N
    
    filename = strcat('batch',(letters(letta)),'.csv'); %concats the batchname string
    Matrix = csvread(filename); %opens it up
    Matrix_new = Matrix([2:end],:); %Eliminates the header strings (first row)
    Time = Matrix_new(:,1);
    num_batteries_inpack = (length(Matrix_new(1,:))-1)/3;

    for n = 1:num_batteries_inpack %For 30 batteries per pack
    insta_voltage_bits = Matrix_new(:,v(n));
    insta_voltage_volts = insta_voltage_bits*(5/4095);
    insta_current = Matrix_new(:,c(n));
    insta_power = insta_current.*insta_voltage_bits;
    insta_capacity = cumtrapz(Time, insta_power);
    capacity_matrix = [capacity_matrix,insta_capacity(length(insta_capacity))];
    end 
    filename = '';
end


















%{
Voltage_bits = Matrix(:,2);
Voltage_volts = Voltage_bits*(5/4095);
Current = Matrix(:,3);
Power = Current.*Voltage_volts;
Result = cumtrapz(Time, Current.*Voltage_volts);
plot(Time,Result)
%}
%This is the part we will use when we get an SD Card text file read in
%{
Time = Matrix(:,1);
Voltage = Matrix(:,2)*(2.5/4095);
i = 5;
E = i.*(cumtrapz(Current, Voltage)); %trapezoidal integration
E_final = E(end);
plot(Time, E)
MatrixC = Matrix(:,3);
plot(Time,Voltage,'y-',Time,MatrixC,'go')
%}


%Function: to accurately parse CSV data obtained from the SD card 

%Matrix for the voltages, current, and temperature where each column is a
%seperate battery 

%{
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
%}
