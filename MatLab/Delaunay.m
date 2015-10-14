function [xi4,xi6] = Delaunay(X)

tes=delaunay(X(:,1),X(:,2));                %Calculo los triangulos

xi4=[];
xi6=[];

for j=1:length(X(:,1))

    xi4(j)=0;
    xi6(j)=0;
    k=0;

    for h=1:length(tes(:,1))

        for s=1:3

            if(tes(h,s)==j)                 %Si en la s-esima posicion esta j

                t=0;
                for p=1:3
                    if p~=s
                        t=t+1;
                        v(t)=tes(h,p);      %Indices
                    end
                end

                r1=[X(v(1),1),X(v(1),2)];   %Coordenadas primer vecino
                r2=[X(v(2),1),X(v(2),2)];   %Coordenadas segundo vecino

                r=[X(j,1),X(j,2)];          %Coordenadas particula central

                k=k+1;
                v=r1-r;
                phi=atan2(v(1),v(2));       %Calculo el angulo entre r1 y el eje x
                xi4(j)=xi4(j)+exp(4*i*phi);
                xi6(j)=xi6(j)+exp(6*i*phi);

                k=k+1;
                v=r2-r;
                phi=atan2(v(1),v(2));       %Calculo el angulo entre r2 y el eje x
                xi4(j)=xi4(j)+exp(4*i*phi);
                xi6(j)=xi6(j)+exp(6*i*phi);
            end
        end
    end
    xi4(j)=abs(xi4(j))/k;
    xi6(j)=abs(xi6(j))/k;
end

