BEGIN{
        c = 0;
}

{
    if($1 == "d")
    {
        c++;
        printf("%s\t%s", $5, $11);
    }
}

END{
    printf("\nNo. of packets dropped = %d\n", c);
}
