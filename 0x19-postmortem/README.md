

Posted by: Esraa Hassan 





On May 7th, 2024, users reported issues accessing our appointment booking system for Spain visa applications, with the system completely unavailable. The problem was identified as a database connection issue, which was resolved by restarting the database service. Measures are being taken to prevent similar incidents in the future.
Outage Duration: May 7th, 2024. 14:00 UTC – 15:30 UTC (approximately 1 hour, 30 minutes).

Timeline:

2024-05-07 14:00: Reports of inability to book appointments for Spain visa applications start pouring in.
2024-05-07 14:10: Technical team begins investigating the issue.
2024-05-07 14:20: Database connectivity issues identified as the potential root cause.
2024-05-07 14:30: Database service restarted to attempt to resolve the issue.
2024-05-07 14:45: Database service back online, but connectivity issues persist.
2024-05-07 15:00: Further investigation reveals misconfiguration in the database connection pool.
2024-05-07 15:15: Misconfiguration corrected, database connection tested successfully.
2024-05-07 15:30: Appointment booking functionality for Spain visa applications fully restored.
2024-05-08 10:00: Postmortem meeting conducted.

Impact:

Customer Impact: Approximately 500 users attempting to book appointments for Spain visa applications were affected by the outage.
Business Impact: Direct financial impact due to potential loss of visa application fees. Additionally, negative impact on customer satisfaction and reputation.

Root Cause(s):

	Technical Cause: Misconfiguration in the database connection pool settings, causing database connections to be exhausted.
	Contributing Factors: Lack of thorough testing in a production-like environment that could have caught the misconfiguration earlier.

	Corrective Actions:

	Immediate Fixes: Restarted the database service to restore connectivity temporarily. Corrected the misconfiguration in the database connection pool settings.
	Preventative Measures:
	Implement automated monitoring to alert on database connectivity issues (Owner: Claire, Deadline: 2024-05-14)
	Enhance testing procedures to include thorough testing of database connection configurations in a production-like environment (Owner: Technical Team, Deadline: 2024-05-21)

	Lessons Learned:

	The criticality of comprehensive testing: Misconfigurations, even in seemingly trivial settings, can have significant impacts on system functionality.
	Proactive monitoring: Investing in automated monitoring systems can help detect issues before they escalate into service outages.

	Communication

	Internal: Effective communication via Slack channels facilitated collaboration and timely resolution of the issue.
	External: Regular updates were posted on our social media channels and website to keep customers informed about the progress of the resolution efforts and the eventual restoration of service.

![IMG_20240508_022011_741](https://github.com/esrAA312/alx-system_engineering-devops/assets/138700352/2a3fb57e-e884-4f4d-936a-c557f6764df4)
