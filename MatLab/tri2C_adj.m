function A = tri2C_adj(T)

% Donne la matrice d'adjacence des points connaissant les triangles
% d'une tesselation

m = max(T(:));
A = sparse([T(:,1) ; T(:,2) ; T(:,1)], ...
            [T(:,2) ; T(:,3) ; T(:,3)], ...
            ones(3*size(T,1),1),m,m);

A = A+A'; %pour symetriser
