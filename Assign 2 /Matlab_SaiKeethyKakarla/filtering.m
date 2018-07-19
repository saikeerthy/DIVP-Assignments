clc;
close all;
clear;
s = imread('cameraman.jpg');
figure;
imshow(s)

for n1=1:3
    for n2=1:3
        h(n1,n2) = 1/9;
    end
end
l=mat2gray(s);
Mn= mean2(l);

h
y1= conv2(l,h);

figure;
imshow(y1);
imwrite(y1,'y1.jpg');
y2=filter2(h,l);

type('filter2')
figure
imshow(y2);
imwrite(y2,'y2.jpg');
[S,HCOL,HROW] = isfilterseparable(h)


for n1=1:256
    
       c1(n1,:)= conv(l(n1,:),HCOL); 
end
for n2=1:258
y3(:,n2)= conv(c1(:,n2),HCOL);
end   
    
%end
%for n2 = 1:258
   
%     for n1=1:256
%     c1(n1,:)= conv(l(n1,:),HCOL); 
%     end
%     k(:,n2)= conv(c1(:,n2),HROW);
% end

figure;
imshow(y3);
imwrite(y3,'y3.jpg');
figure;

freqz2(h,[64 64]); 
kk= [1,0,0;0,0,0;0,0,0;];

        h2 = kk-h;
   
y4=conv2(l/Mn,h2);


figure;

imshow(y4);
imwrite(y4,'y4.jpg');
%fftA = fft2(double(h2));


