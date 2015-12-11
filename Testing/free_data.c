
oid free_data(int *****data, size_t dim1, size_t dim2,size_t dim3,size_t dim4)
{
    size_t i, j,k,b;

    for (i=0; i < dim1; ++i) {
        if (data[i] != NULL) {
            for (j=0; j < dim2; ++j) {
                if(data[i][j] != NULL) {
                    for(k=0;k < dim3) {
                        if(data[i][j][k] != NULL) {
                            for(b=0;k < dim4) {
                                if(data[i][j][k][b] != NULL) {
                                    free(data[i][j][k][b]);
                                }
                            }
                            free(data[i][j][k])
                            }
                        }
                    free(data[i][j]);
                    }
                }
            free(data[i]);
        }
    }
    free(data);
}