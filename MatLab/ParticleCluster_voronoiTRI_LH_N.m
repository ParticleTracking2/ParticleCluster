function [Xcc,Ycc]=ParticleCluster_voronoiTRI_LH_N(X,Y,Q4,Vc,Q4c,Nclc,caso)

    %X particle coordinates
    %Y particle coordinates
    %Q4 absolute value per particle
    %Voronoi area threshold
    %Q4 threshold
    %count clusters larger than Nclc
    %caso define cual criterio se usará (Av<Vc caso 1;Q4>Q4c caso 2;Av<Vc y Q4>Q4c caso 3) 
    
    % Xc=[];
    % Yc=[];
    % idc=[];
    % Xcc=[];
    % Ycc=[];
    % idcc=[];
    TRI = delaunay(X,Y);
    %NC=length(TRI); %number of triangles
    N=length(X);
    Vol=zeros(N,1);
    
    %%%%%%%Voronoi criterion to select solid clusters%%%%%%%%%%%%%%%%%%%%%
    pos=[X Y];
    [V,C] = voronoin(pos);
    
    %%create the new cell of Voronoi with empty array for the particles to eliminate such as Voronoi area Vol>Vc     
    for i=1:N %nb cells=nb particles
        ind=C{i};
        Vol(i,1)=polyarea(V(ind,1),V(ind,2));
    end
    
    if caso == 1, 
        %fprintf('caso Av<75\n');
        nums=find(Vol<Vc);
    elseif caso == 2
      
        %fprintf(['caso Q4 > ' num2str(Q4c) ' \n']);
        nums=find(Q4>Q4c);
    elseif caso == 3, 
        %fprintf('caso Av<75 and Q4>0.7\n');
        nums=find(Q4>Q4c & Vol<Vc);
    end
    % Xc=X(nums);
    % Yc=Y(nums);
    % idc=id(nums);
    TT={};

    for ii=1:length(nums)
        %[ind,~,val]=find(TRI==nums(ii));
        %[ind,~,val]=find(TRI(:,1)==nums(ii) | TRI(:,2)==nums(ii) | TRI(:,3)==nums(ii))
        [ind,~,val]=find(TRI(:,1)==nums(ii));
        cc = 1;
        indOK = [];
        
        if caso == 1, 
        
            for iii=1:length(ind), 
                Volv1 = Vol(TRI(ind(iii),2));
                Volv2 = Vol(TRI(ind(iii),3));
                if Volv1<=Vc || Volv2<=Vc,
                    indOK(cc) = ind(iii);
                    cc = cc + 1;
                end
            end
            [ind,~,val]=find(TRI(:,2)==nums(ii));
            for iii=1:length(ind), 
                Volv1 = Vol(TRI(ind(iii),1));
                Volv2 = Vol(TRI(ind(iii),3));
                if Volv1<=Vc || Volv2<=Vc,
                    indOK(cc) = ind(iii);
                    cc = cc + 1;
                end
            end
            [ind,~,val]=find(TRI(:,3)==nums(ii));
            for iii=1:length(ind), 
                Volv1 = Vol(TRI(ind(iii),1));
                Volv2 = Vol(TRI(ind(iii),2));
                if Volv1<=Vc || Volv2<=Vc,
                    indOK(cc) = ind(iii);
                    cc = cc + 1;
                end
            end
            
        elseif caso == 2, 
        
            for iii=1:length(ind), 
                q4v1 = Q4(TRI(ind(iii),2));
                q4v2 = Q4(TRI(ind(iii),3));
                if q4v1>=Q4c || q4v2>=Q4c,
                    indOK(cc) = ind(iii);
                    cc = cc + 1;
                end
            end
            [ind,~,val]=find(TRI(:,2)==nums(ii));
            for iii=1:length(ind), 
                q4v1 = Q4(TRI(ind(iii),1));
                q4v2 = Q4(TRI(ind(iii),3));
                if q4v1>=Q4c || q4v2>=Q4c,
                    indOK(cc) = ind(iii);
                    cc = cc + 1;
                end
            end
            [ind,~,val]=find(TRI(:,3)==nums(ii));
            for iii=1:length(ind), 
                q4v1 = Q4(TRI(ind(iii),1)); %%%%AQUI ESTABA EL ERROR, la linea era esta: q4v1 = Q4(TRI(ind(iii),3));%%%%
                q4v2 = Q4(TRI(ind(iii),2));
                if q4v1>=Q4c || q4v2>=Q4c,
                    indOK(cc) = ind(iii);
                    cc = cc + 1;
                end
            end
            
        elseif caso == 3, 
        
            for iii=1:length(ind), 
                q4v1 = Q4(TRI(ind(iii),2));
                q4v2 = Q4(TRI(ind(iii),3));
                Volv1 = Vol(TRI(ind(iii),2));
                Volv2 = Vol(TRI(ind(iii),3));
                if (Volv1<=Vc && q4v1>=Q4c) || (Volv2<=Vc && q4v2>=Q4c),
                    indOK(cc) = ind(iii);
                    cc = cc + 1;
                end
            end
            [ind,~,val]=find(TRI(:,2)==nums(ii));
            for iii=1:length(ind), 
                q4v1 = Q4(TRI(ind(iii),1));
                q4v2 = Q4(TRI(ind(iii),3));
                Volv1 = Vol(TRI(ind(iii),1));
                Volv2 = Vol(TRI(ind(iii),3));
                if (Volv1<=Vc && q4v1>=Q4c) || (Volv2<=Vc && q4v2>=Q4c),
                    indOK(cc) = ind(iii);
                    cc = cc + 1;
                end
            end
            [ind,~,val]=find(TRI(:,3)==nums(ii));
            for iii=1:length(ind), 
                q4v1 = Q4(TRI(ind(iii),1));
                q4v2 = Q4(TRI(ind(iii),2));
                Volv1 = Vol(TRI(ind(iii),1));
                Volv2 = Vol(TRI(ind(iii),2));
                if (Volv1<=Vc && q4v1>=Q4c) || (Volv2<=Vc && q4v2>=Q4c),
                    indOK(cc) = ind(iii);
                    cc = cc + 1;
                end
            end
        end

        if length(indOK)>=1,
            c=indOK';
            TT{ii}=c;
        end
    end

    T=[];
    for jj=1:numel(TT)
        T=[T;TT{jj}];
    end


    A=tri2C_adj(TRI(T,:)); %give the adjacency matrix of all the triangles such as Voronoi area Vol<Vc or Q4>=Q4c
    out = adj2blob(A); %transform the adjacency matrix into clusters : out=cell containing the indice of particles in each clusters

    n=1;
    Nc=0;
    for ij=1:length(out)
        if length(out{ij})>Nclc % count clusters larger than Nclc
            indc(n)=ij; % out=cell indices of the clusters larger than Nclc
            n=n+1;    
            Nc=Nc+1;
            Lc(Nc)=length(out{ij});
            %Xc=[Xc; X(out{ij})];
            %Yc=[Yc; Y(out{ij})];
            %idc=[idc; id(out{ij})];
        end
    end
    outc={};
    for q=1:length(indc)
    outc{q}=out{indc(q)};
    end

    [~,indm]=max(Lc);

    Xcc=X(outc{indm}); 
    Ycc=Y(outc{indm});
end
%idcc=id(outc{indm});



