function out = adj2blob(A,opt)
%
% out = adj2blob(A,[opt = 0])
%
% ADJ2BLOB converts an adjacency matrix into connex blobs
%
% * If opt is 1, informations are displayed

if nargin<2, opt = 0; end

% ---------------------------------------------------

A(find(eye(size(A)))) = 0;  % Remove the self part

if opt, fprintf('\tBlobification '); tic; end

p = symrcm(A);
B = A(p,p);

out = {};
tmp = [1 find(~([sum(triu(B),1) 1] + [1 sum(triu(B),2)'])) size(B,1) size(B,1)+1];

for i = 1:numel(tmp)-1
    out{i,1} = p(tmp(i):tmp(i+1)-1)';
    if (opt & ~mod(i,300)), fprintf('.'); end
end

if opt, fprintf('\t%0.2f sec. (%i blobs found)\n',toc,numel(out)); end

% % % == PREVIOUS METHOD : SLOWER =======================
% % 
% % % Densification of the adjacency network
% % if opt, fprintf('\tDensification '); tic; end
% % 
% % A(find(sparse(eye(size(A,1))))) = 0;    % Remove the self part
% % 
% % B = A*A;
% % C = A+B;
% % i = 0;
% % while numel(find(B~=A))
% %     % for k = 1:10
% % 
% %     A = A+B;
% %     B = B*A;
% %     C = A;
% %     
% %     i = i+1;
% %     if opt, fprintf('.'); end
% % end
% % 
% % C = C + sparse(eye(size(C,1)));         % Add the self part
% % 
% % if opt, fprintf('\t%0.2f sec. (There was %i iterations)\n',toc,i); end
% % 
% % % Blobification
% % 
% % if opt, fprintf('\tBlobification '); tic; end
% % 
% % blo = cell(0,2);
% % for i = 1:size(A,1)
% %     I = find(C(i,:));
% %     if numel(I)
% %         if ~ismember(min(I), cell2mat(blo(:,1)))
% %             blo{end+1,1} = min(I);
% %             blo{end,2} = I;
% %         end
% %     end
% %     if (opt & ~mod(i,300)), fprintf('.'); end
% % end
% % 
% % out = blo(:,2);       % On ne garde que ce qui nous interesse
