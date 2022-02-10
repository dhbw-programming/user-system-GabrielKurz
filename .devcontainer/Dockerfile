FROM mcr.microsoft.com/vscode/devcontainers/cpp:debian

COPY ./hooks /dhbw/git-hooks
RUN chmod +x /dhbw/git-hooks/post-commit
COPY .gitconfig /home/vscode/.gitconfig 
