function newImage = escalaN (img, dx, dy, tipo)
  scale = [dx dy];
  oldSize = size(img) ;
  newSize = max(floor(scale .* oldSize(1:2)), 1);
  
  % divide um intervalo em n particoes  
  rowIndex = linspace(1, oldSize(1), newSize(1));
  colIndex = linspace(1, oldSize(2), newSize(2));
  
  if tipo == 1 %com interpolacao
    [x y] = meshgrid(1:oldSize(1), 1:oldSize(2)); #vetor referente a matriz da imagem original
    [XI YI] = meshgrid(rowIndex, colIndex); #vetor referente a matriz da imagem nova
    outputImage = interp2(x, y, img, XI, YI); #interpola elas
  else % sem interpolacao
    % Calcula um conjunto de amostras de indices:
    rowIndex = min(round(rowIndex), oldSize(1));
    colIndex = min(round(colIndex), oldSize(2));
    %A partir da antiga imagem, gera a nova com os indices encontrados
    outputImage = img(rowIndex, colIndex,:);
  endif
  newImage = uint8(outputImage) ;  
endfunction
