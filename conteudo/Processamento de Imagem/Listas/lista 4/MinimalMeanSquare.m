function newImage = MinimalMeanSquare(img, tam, ruido)
  img = double(img);
  
  varRuido = ruido;
  
  mediaLocal = colfilt(img, [tam tam], 'sliding', @mean);
  varLocal = colfilt(img, [tam tam], 'sliding', @var);
  
  newImage = (1-(varRuido./varLocal)) .* img + ((varRuido./varLocal).*mediaLocal);
  newImage = uint8(newImage);
endfunction