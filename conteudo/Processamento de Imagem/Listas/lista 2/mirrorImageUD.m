function newImage = mirrorImageUD (img)
  newImage = zeros(size(img));
  
  for i=1:size(newImage, 1)
    for j=1:size(newImage, 2)
      newImage(i,j,:) = img((size(img, 1) - i + 1), j, :);
    endfor
  endfor
endfunction
