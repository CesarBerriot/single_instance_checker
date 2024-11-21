#include <windows.h>
#include <hard_assert.h>
#include <make_string.h>

#define LIBRARY_NAME "SIC"

void sic_check(char application_name[])
{	ha_assert(application_name, LIBRARY_NAME, "NULL application name");
	ha_assert(strlen(application_name), LIBRARY_NAME, "empty application name");

	char guid[] = "{E4A2C332-A0EB-4757-A4C5-B333BF729956}";
	char * mutex_id = ms_make("%s %s", application_name, guid);

	SetLastError(0);
	if(OpenMutexA(SYNCHRONIZE, FALSE, mutex_id))
		ha_abort(LIBRARY_NAME, "an instance of the application already exists!");
	else
		ha_assert(GetLastError() == ERROR_FILE_NOT_FOUND, LIBRARY_NAME, "an unknown win32 mutex access error occurred");
	ha_assert(CreateMutexA(NULL, TRUE, mutex_id), LIBRARY_NAME, "win32 mutex creation failure");
}
