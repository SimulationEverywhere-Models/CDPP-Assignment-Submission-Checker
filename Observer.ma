[Top]
components : Observer@ObserverType 
out : response 
in : ml_out tc_out pc_out 
Link : ml_out ml_out@Observer
Link : tc_out tc_out@Observer
Link : pc_out pc_out@Observer
Link : response@Observer response

[Observer]
response_time : 00:00:10:00


