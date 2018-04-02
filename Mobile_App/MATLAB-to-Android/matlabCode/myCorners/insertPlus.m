function I = insertPlus(I,Pts)
% Copyright 2014 - 2015 The MathWorks, Inc.

[h,w] = size(I);
ind = sub2ind([h w],Pts(:,2),Pts(:,1));
ind2 = bsxfun(@plus,ind,[-3 -2 -1 0 1 2 3 -h -2*h -3*h h 2*h 3*h]);
ind2(ind2 < 1) = 1;
ind2(ind2 > numel(I)) = numel(I);
I(unique(sort(ind2(:)))) = uint8(255);