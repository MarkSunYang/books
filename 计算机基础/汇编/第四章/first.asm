assume cs:codesg


# 伪指令 
codesg segment

        mov ax,0123H            编              B8 23 01
        mov bx 0456H            译              BB 56 04
        add ax,bx               连              03 C3
        add ax,ax               接              03 C0

        mov ax,4c00H                            B8 00 4C
        int 21H                                 CD 21

codesg ends

end


