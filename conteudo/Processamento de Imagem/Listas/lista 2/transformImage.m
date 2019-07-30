function newImage = transformImage (img, ang) 
  M = [cosd(ang) (-1)*(sind(ang)) 0; sind(ang) cosd(ang) 0; 0 0 1];
  structure = maketform('affine', M);
  newImage = imtransform(img, structure, 'bilinear');
endfunction
