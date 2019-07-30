img = imread('/home/marcos/ufop/pdi/lista_2/lenna_rgb512.jpg');
pkg load image
img = rgb2gray(img);

# 1) Rotacione a imagem
imgRotated = rotateImage(img, 90);
imshow(imgRotated, []);

# 2) Espelhar a imagem
imgEspelhada = mirrorImageLR(img);
imgEspelhada = mirrorImageUD(imgEspelhada);
imshow(imgEspelhada, []);

# 3) Modificar a escala
imgEscala = escalaN(img, 0.5, 0.5, 1);
imshow(imgEscala, []);

# 4) Reimplementar Rotate com imtransform
imgTransform = transformImage(img, 45);
imshow(imgTransform, []);