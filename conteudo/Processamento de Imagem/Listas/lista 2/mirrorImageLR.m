function newImage = mirrorImageLR (img)
  newImage = zeros(size(img));
  
  for i=1:size(newImage, 1)
    for j=1:size(newImage, 2)
      newImage(i,j,:) = img(i, (size(img, 2) - j + 1), :);
    endfor
  endfor
endfunction
