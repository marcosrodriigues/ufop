function newImage = rotateImage (img, ang)
  newImage = zeros(size(img));
  
  midx=ceil(((size(img,1)+1)/2));
  midy=ceil(((size(img,2)+1)/2));
 
  for i=1:size(newImage, 1)
    for j=1:size(newImage, 2)
      x = (i-midx)*cosd(ang)-(j-midy)*sind(ang);
      y = (i-midx)*sind(ang)+(j-midy)*cosd(ang);
      x = round(x)+midx;
      y = round(y)+midy;
      
      if (x >= 1 && y >= 1 && x <= size(newImage, 1) && y <= size(newImage, 2))
        newImage(x, y) = img(i, j);
      endif
    endfor
  endfor
endfunction