%very much not done yet
%please don't try to understand it
clear;
close all;
clc;

%create dummy 100x91 matrix of data
for i=1:91 %iterate through columns
    for j=1:100 %iterate through rows
        if i==1 %timestamp column
            %batchA(j, i) = 100*j;
            batchA(j,i) = 1;
            %batchB(j, i) = 100*j;
        end
        if mod((i - 2), 3) == 0 %battery_y voltage columns (2, 5, 8, 11...)
            %fill with random voltages ranging from 1-11 V
            %batchA(j, i) = rand()*10 + 1;
            batchA(j,i) = 2;
        end
        if mod(i, 3) == 0 %battery_y current columns (3, 6, 9, 12...)
            %fill with random currents ranging from 0.1-51 A
            %batchA(j, i) = rand()*5 + 0.1;
            batchA(j,i) = 3;
        end
        if mod((i - 1), 3) == 0 %battery_y temperature columns (4, 7, 10, 13...)
            %fill with random temperatures ranging from 40-80 F
            %batchA(j, i) = rand()*40 + 40;
            batchA(j,i) = 4;
        end
    end
end

%TODO: initialize csv writer thing?

%TODO: write column labels to .csv file

%write batchA matrix to batchA.csv
csvwrite('batchA.csv', batchA, 1, 1);