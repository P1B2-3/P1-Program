void LoadingScreen(int i, int maxTimesMod, int maxTimes,int b) {

    if(i == 0 ) {
        
        printf("Loading %i%%",b);
        
    }
    else if(i % 20 == maxTimesMod && i != maxTimes && b < 10) {
        
        printf("\rLoading %i%%",b);
        
    }
    else if(i % 20 == maxTimesMod && i != maxTimes && b > 10) {
        
        printf("\rLoading %i%%",b );
        
    }
    else if(i == maxTimes) {
        printf("\rLoading %i%%\n",b );
    }
    
}