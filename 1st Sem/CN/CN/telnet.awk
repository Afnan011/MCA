BEGIN{
    count = 0; sent1 = 0; sent2 = 0; rec = 0;
}

{
    if($1 == "d")
    {
        count++;
    }
    
    else if($1 == "+" && $3 == 0 && $4 == 2)
    {
        sent1++;
    }
    
    else if($1 == "+" && $3 == 1 && $4 == 2)
    {
        sent2++;
    }
    else if($1 == "r" && $3 == 2 && $4 == 3)
    {
        rec++;
    }
}

END{
    printf("No. of packets dropped = %d\n", count);
    printf("packets sent from source Node 0: %d\n", sent1);
    printf("packets sent from source Node 1: %d\n", sent2);
    
    print("Total Packets recieved: %d\n", rec);
    
    sent = sent1+sent2;
    printf("packet delivery ratio is: %0.2f\n", (sent/rec)*100);
}
