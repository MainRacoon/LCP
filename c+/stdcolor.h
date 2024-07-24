#ifndef _CP_STDCOLOR
#define _CP_STDCOLOR

typedef struct{
    const char
            *black,
            *red,
            *green,
            *yellow,
            *blue,
            *magenta,
            *cyan,
            *white;
}colorscheme;

struct{
    struct{
        colorscheme normal;
        colorscheme bold;
        colorscheme underline;
        struct{
            colorscheme bold;
            colorscheme normal;
        }highintensity;

    }text;
    struct{
        colorscheme normal;
        colorscheme highintensity;
    }background;
    const char*reset;
}stdcolor={
        .reset="\e[0m",
        .text={
                .normal={
                        .black="\e[0;30m",
                        .red="\e[0;31m",
                        .green="\e[0;32m",
                        .yellow="\e[0;33m",
                        .blue="\e[0;34m",
                        .magenta="\e[0;35m",
                        .cyan="\e[0;36m",
                        .white="\e[0;37m"
                },
                .bold = {
                        .black="\e[1;30m",
                        .red="\e[1;31m",
                        .green="\e[1;32m",
                        .yellow="\e[1;33m",
                        .blue="\e[1;34m",
                        .magenta="\e[1;35m",
                        .cyan="\e[1;36m",
                        .white="\e[1;37m"
                },
                .underline={
                        .black="\e[4;30m",
                        .red="\e[4;31m",
                        .green="\e[4;32m",
                        .yellow="\e[4;33m",
                        .blue="\e[4;34m",
                        .magenta="\e[4;35m",
                        .cyan="\e[4;36m",
                        .white="\e[4;37m"
                },
                .highintensity={
                        .normal={
                                .black="\e[0;90m",
                                .red="\e[0;91m",
                                .green="\e[0;92m",
                                .yellow="\e[0;93m",
                                .blue="\e[0;94m",
                                .magenta="\e[0;95m",
                                .cyan="\e[0;96m",
                                .white="\e[0;97m"
                        },
                        .bold={
                                .black="\e[1;90m",
                                .red="\e[1;91m",
                                .green="\e[1;92m",
                                .yellow="\e[1;93m",
                                .blue="\e[1;94m",
                                .magenta="\e[1;95m",
                                .cyan="\e[1;96m",
                                .white="\e[1;97m"
                        }
                }
        },
        .background={
                .normal={
                        .black="\e[40m",
                        .red="\e[41m",
                        .green="\e[42m",
                        .yellow="\e[43m",
                        .blue="\e[44m",
                        .magenta="\e[45m",
                        .cyan="\e[46m",
                        .white="\e[47m"
                },
                .highintensity={
                        .black="\e[0;100m",
                        .red="\e[0;101m",
                        .green="\e[0;102m",
                        .yellow="\e[0;103m",
                        .blue="\e[0;104m",
                        .magenta="\e[0;105m",
                        .cyan="\e[0;106m",
                        .white="\e[0;107m"
                }
        }
};




#endif