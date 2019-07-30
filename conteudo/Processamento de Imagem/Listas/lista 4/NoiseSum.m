function [nimg, figs] = NoiseSum(img, n)
  nimg = zeros(size(img));
  figs = zeros(size(img,1), size(img,2), n);
  for i = 1 : n
    figs(:,:,i) = imnoise(img, 'salt & pepper');
  end
  figs = sort(figs, 3);
  nimg = uint8(figs(:,:,floor(n/2)));
endfunction