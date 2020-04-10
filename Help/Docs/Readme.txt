#注意事项
1. 脑子里要有源代码文件这个概念。写程序不是说就在框框里写一堆代码然后就能跑了！代码都要写成文件保存起来（到硬盘里），然后才有后续的工作；
2. VS Code是支持多语言的编辑器，并不只为C/C++服务，所以还要确保把代码文件的后缀名写对，C语言的后缀名是.c，C++的是.cpp。这是VS Code区分你代码类型的标志；
3. 上面安装的"C/C++"插件提供了对这两门语言的基本支持。C跟C++是两门不同的语言，请向你的老师问清楚学的是哪一门。无论是在.c文件里敲C++代码，还是在.cpp文件里敲C代码，都是XX的行为。
4. 编写C/C++程序有两个基本步骤，一是把代码文件变成程序文件，这叫编译或生成，是编译器做的事；二才是把刚刚生成的程序跑起来，这叫执行，是操作系统做的事；
5. 代码的编译和一般程序的执行，都是在命令行的环境下进行的，输入输出也是在这里面。VS Code的优势之一，就是把系统的命令行集成进了软件内部，名唤“终端”，从而不必再开新窗口。

#相关目录标识符
    ${workspaceFolder} - the path of the folder opened in VS Code
    ${workspaceRootFolderName} - the name of the folder opened in VS Code without any slashes (/)
    ${file} - the current opened file
    ${relativeFile} - the current opened file relative to workspaceRoot
    ${fileBasename} - the current opened file's basename
    ${fileBasenameNoExtension} - the current opened file's basename with no file extension
    ${fileDirname} - the current opened file's dirname
    ${fileExtname} - the current opened file's extension
    ${cwd} - the task runner's current working directory on startup
    ${lineNumber} - the current selected line number in the active file
#调试运行说明
1. simplefile：code-runner直接运行(Terminal)；Task->build+run(Terminal)<ctrl+shift+B>；系统自带Debug(Terminal/externendTerminal)<F5>
2. project：Cmake->build<F7>、run(Terminal)<shift+F5>、Degug(同系统自带Debug)<shift+F6>；Task->build+run(Terminal)<ctrl+shift+B>；系统自带Debug(同上)<F5>
3. 单个文件用cpde-runner/mingw，工程用Cmake+mingw
4. 注意<ctrl+F5>是系统自带的Runwithoutdebuging，既直接运行，但是对C/Cpp语言程序没有用，还是会直接调试，对其他语言程序有效,所以要想直接运行，只能通过code-runner、Task和Cmake的Runwithoutdebuging<shift+F5>
#编码问题
1. 文件乱码：更改编码格式即可
2. 输出乱码：VS Code输出窗口内置为UTF-8,不同于setting.json中的encoding,而对于输出的汉语，在某些情况下会出现乱码，所以遇到乱码再解决，目前没有办法一次性解决
#运行问题
所有要运行的文件必须放到含有.vscode的文件夹中，然后在相应的工作区中打开Floder，在此环境下进行编写、编译、运行、调试等工作