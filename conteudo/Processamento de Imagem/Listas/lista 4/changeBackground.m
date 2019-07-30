function newImage = changeBackground (img, imgmask, inc)
  newImage = cat(3, img, img, img);
  for i = 1 : size(img,1)
    for j = 1 : size(img,2)
      if imgmask(i,j) == 0
        newImage(i,j,1) = img(i,j) * inc;
        newImage(i,j,2) = img(i,j) * inc;
        newImage(i,j,3) = img(i,j) * inc * 2;
      endif
    endfor
  endfor
endfunction