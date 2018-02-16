%caps = capacity_matrix; %%WHEN DONE
caps = 0.5*rand(1,416)+3;

%IMPORTANT --> Upload actual battery capacity into caps vector
%Pack matrix is the pack of batteries, position matrix is the number of the battery (1-416).
%indexCells contains the ordered definition of the batteries (A1-A36,B1-B36,etc...)

capsTest = caps;

caps = sort(caps);
capssecond = [];
for f = 1:length(caps)
    capssecond(f) = f;
end

capsFinal = [caps;capssecond];
capsFinalTest = [capsTest;capssecond];
tot = 0;
count = 1;
up = 1;

for x = 1:416 % inding capacity of cells to compare with later
    tot = tot + caps(x);
end


avg = tot/416;
pack = zeros(13,32); %Sets up empty matrix
for i = 1:2:13 %iterates over every other slot in a pack
   for j = 1:32 %iterates through each battery pack
       pack(i,j) = caps(count); %Adds low value capacity to first pack
       count = count + 1;
    end
end


for i = 2:2:12 %iterates over every other slot in a pack
    for j = 1:32
        pack(i,33-j) = caps(count); %Adds high value capacity to first pack
        count = count + 1;
    end
end

letters = ["A","B","C","D","E","F","G","H","I","J","K","L","M","N"];
indexCells = {};
firstRow = capsFinalTest(1,:);
for i = 1:13
    for j = 1:32
        value = pack(i,j);
        if(i == 1 && j == 1)
            originalNum = find(firstRow == value);
            firstRow(originalNum) = -5;
        else
            originalNum = [originalNum, find(firstRow == value)];
            firstRow(originalNum) = -5;
        end
    end
end

count = 1;
for i = 1:13 %iterates over every other slot in a pack
   for j = 1:32 %iterates through each battery pack
       position(i,j) = originalNum(count); %Adds low value capacity to first pack
       count = count + 1;
    end
end


for i = 1:13
    for j = 1:32
        x = position(i,j);
        count = 1;
        while(x > 32)
            x = x - 32;
            count = count + 1;
        end
        indexCells{i,j} = letters(count) + string(x);
    end
end

%Pack matrix is the pack of batteries, position matrix is the number of the battery (1-416).
%indexCells contains the ordered definition of the batteries (A1-A36,B1-B36,etc...)
%avg
sums = sum(pack/13)