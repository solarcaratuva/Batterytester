caps = 0.5*rand(1,416)+3;
    
% Upload actual battery capacity into caps vector

caps = sort(caps);
capssecond = [];
for f = 1:length(caps)
    capssecond(f) = f;
end

capsFinal = [caps;capssecond];
tot = 0;
count = 1;
up = 1;

for x = 1:416 % inding capacity of cells to compare with later
    tot = tot + caps(x);
end


avg = tot/416;
pack = zeros(13,32); %Sets up empty matrix
letters = ["A","B","C","D","E","F","G","H","I","J","K","L","M","N"];
indexCells = {};
for i = 1:2:13 %iterates over every other slot in a pack
   for j = 1:32 %iterates through each battery pack
       pack(i,j) = caps(count); %Adds low value capacity to first pack
       pack2(i,j) = capsFinal(2,count);
       count = count + 1;
    end
end


for i = 2:2:12 %iterates over every other slot in a pack
    for j = 1:32
        pack(i,33-j) = caps(count); %Adds high value capacity to first pack
        pack2(i,33-j) = capsFinal(2,count); %corresponds the original battery to its new location
        count = count + 1;
    end
end

for i = 1:13
    for j = 1:32
        x = pack2(i,j);
        m = 0;
        f = x;
        while(x > 32)
            m = m+1;
            x = x-32;
        end
        indexCells{i,j} = letters(i)+string(x);
    end
end


%Pack is the pack of batteries, pack2 is the number of the battery (1-416).
%IndexCells contains the ordered definition of the batteries
%(A1-A36,B1-B36,etc...)
%avg
%sums = sum(pack/13)
