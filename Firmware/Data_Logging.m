%Temporary to fill in text file
x = 0:1:4095;
y = 0:1:4095;
z = 10:1:4095;
A = sqrt(x);
B = sqrt(y);
C = sqrt(z);
fileID = fopen('dummy_data.txt','w');  
for k = 1: 11
fprintf(fileID,'%1.5f,',A(k));
fprintf(fileID,'%1.5f,',B(k));
fprintf(fileID,'%1.5f\r\n',C(k));
end
fclose(fileID);

%{
20 files --> each battery
every time increment you have:
20 times
20 volts
%}


%This is the part we will use when we get an SD Card text file read in
Matrix = dlmread('dummy_data.txt',',');
Time = Matrix(:,1);
Voltage = Matrix(:,2)*(2.5/4095);
i = 5;
E = i.*(cumtrapz(Time, Voltage));
E_final = E(end);
plot(Time, E)
%MatrixC = Matrix(:,3);
%plot(Time,Voltage,'y-',Time,MatrixC,'go')