unsigned rightrot(unsigned x,int n)
{
    return((x >> n) | (x << (32-n)));
} //Rotating to the bits to right. Book uses mostly one line returns so I try to do the same.I don't know if that's the best pracitce or not but I do.
