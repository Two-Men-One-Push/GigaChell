# GigaChell
> 42 minishell project by [@ethebaul](https://github.com/CyberOne) x [@ebini](https://github.com/saumon-brule)

## Presentation
The minishell project aims to reproduce most basic shell behavior. This includes pipe, redirection, here doc and environment variables (setting and expanding).
This will provide us important knowledge about how basic Unix mechanisms such as pipes, signals, processus and obviously **shell** work. \
Minishell is also the first group project of 42, introducing team woking and use of git as a tool to handle versionning and provide an efficient workflow between students

## Summary

## Operator
- ``&&`` :
- ``||`` :
- ``|`` :
- ``()`` :
- ``>`` : preceeds a file that will be replace the current stdout of the
- ``>>`` : preceeds a file that will be open to be the new stdout of the command (The difference with above is that the new content will be append to the file and will not overwrite it)
- ``<`` : preceeds a file that will be open to be the new stdin of the command
- ``<<`` : preceeds a limiter, it will read the stdin until the line is exactly the same as the delimiter. This operator (here document) is quite special because it is the first to be parsed. Every here-doc will need to be fulfilled before parsing/executing any command. Its unlinear behavior alone makes minishell hard.