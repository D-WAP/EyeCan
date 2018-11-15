vid=videoinput('winvideo',1);
set(vid, 'FramesPerTrigger', Inf);
set(vid, 'ReturnedColorspace', 'rgb')
 B = Bluetooth('HC-05', 1); 
  fopen(B);
preview(vid)
start(vid)
filas=size(vid,1);
columnas=size(vid,2);
centro_fila=round(filas/2);
centro_columna=round(columnas/2);
figure(1);
while true
   data = getsnapshot(vid);
   data = imresize(data,1);
       diff_im = rgb2gray(data);

    subplot(212)
    piel=~im2bw(diff_im,0.18);
    %     --
    piel=bwmorph(piel,'close');
    piel=bwmorph(piel,'open');
    piel=bwareaopen(piel,200);
    piel=imfill(piel,'holes');
    imagesc(piel);
    L=bwlabel(piel);
    out_a=regionprops(L);
    N=size(out_a,1);
    if N < 1 || isempty(out_a) 
        solo_cara=[ ];
        disp('Stop');
        fwrite(B,'0');
        continue
    end
    areas=[out_a.Area];
    [area_min pam]=max(areas);
    subplot(211)
    imagesc(diff_im);
    colormap gray
    hold on
    rectangle('Position',out_a(pam).BoundingBox,'EdgeColor',[1 0 0],...
        'Curvature', [1,1],'LineWidth',2)
    centro=round(out_a(pam).Centroid);
    X=centro(1);
    Y=centro(2);
    disp(X)
    
    plot(X,Y,'g+')
    %     
    text(X+10,Y,['(',num2str(X),',',num2str(Y),')'],'Color',[1 1 1])
    if X>40 && X<112
                    fwrite(B,'1');
                    disp('Forward');
      
    elseif X>112
                    fwrite(B,'4');
                    disp('Right');
    elseif X<40
                    fwrite(B,'3');
                    disp('Left');
    end
    hold off
    % --
    drawnow;
    flushdata(vid)
end
stop(vid);
flushdata(vid);


