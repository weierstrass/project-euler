clc 

A = [5616185650518293
3847439647293047
5855462940810587
9742855507068353
4296849643607543
3174248439465858
4513559094146117
7890971548908067
8157356344118483
2615250744386899
8690095851526254
6375711915077050
6913859173121360
6442889055042768
2321386104303845
2326509471271448
5251583379644322
1748270476758276
4895722652190306
3041631117224635
1841236454324589
2659862637316867];

cor = [ 2 1 3 3 3 1 2 3 1 2 3 1 1 2 0 2 2 3 1 3 3 2];
length(cor)

res = ones(10, 16); %res(3, 2) = "prob." for 2nd digit to be 3  

for j=1:22
   for i=1:16
     n = (mod(A(j,:), 10^i)  - mod(A(j,:), 10^(i-1))) / 10^(i-1);
     p = n;
     if(n == 0) p = 10; end
     res(p, i) = res(p, i) * cor(j);
   end
end

res(:,16)

res
cand = ones(size(res));

for i=1:10
   for j=1:16
      [C, I] = max(res(:,j));
      
      cand(i, j) = I;
      if(I == 10) cand(i,j) = 0; end
      res(I, j) = -1;
   end
end
cand
res(:, 2)

sign(res - (mean(res)'*ones(1,10))')