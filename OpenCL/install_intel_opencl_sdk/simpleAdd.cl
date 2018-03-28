__kernel void simpleAdd(
                       __global int *pA,                      
                       __global int *pB,                      
                       __global int *pC)                      
{                                                              
    const int id = get_global_id(0);                                 
    pC[id] = pA[id] + pB[id];                                 
}
