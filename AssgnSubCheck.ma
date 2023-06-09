[Top]
components : Assignment@AssignmentType Observer@ObserverType ModelName 
out : response 
in : submit 
Link : submit submit@Assignment
Link : details@Assignment details@ModelName
Link : pc_out@ModelName pc_out@Observer
Link : tc_out@ModelName tc_out@Observer
Link : ml_out@ModelName ml_out@Observer
Link : response@Observer response

[Assignment]
assgn_time : 00:00:05:00

[Observer]
response_time : 00:00:10:00

[ModelName]
components : TimeChecker@TimeCheckerType PlagiarismChecker@PlagiarismCheckerType MailChecker@MailCheckerType 
out : tc_out pc_out ml_out 
in : details 
Link : details details@TimeChecker
Link : details details@PlagiarismChecker
Link : details details@MailChecker
Link : ml_out@MailChecker ml_out
Link : pc_out@PlagiarismChecker pc_out
Link : tc_out@TimeChecker tc_out

[TimeChecker]
tc_time : 00:00:05:00

[PlagiarismChecker]
pc_time : 00:00:05:00

[MailChecker]
ml_time : 00:00:05:00



