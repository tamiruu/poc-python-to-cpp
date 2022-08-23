#include "helper.h"

bool checkName(std::string& name, int pos, const std::string& file_content)
{
	bool invalid = false;
	for (int i = 0; i < pos; i++)
	{
		if (file_content[i] == ' ' || file_content[i] == '\t')
		{
			if (name.size() == 0)
				continue;
			for (; i < pos; i++)
			{
				if (!(file_content[i] == ' ' || file_content[i] == '\t')) {
					invalid = true;
					break;
				}
			}
			if (invalid)
				break;
		}
		if ((file_content[i] >= 'a' && file_content[i] <= 'z') || (file_content[i] >= 'A' && file_content[i] <= 'Z') || file_content[i] == '_')
			name += file_content[i];
		if (file_content[i] >= '0' && file_content[i] <= '9' && name.size() > 0)
			name += file_content[i];
	}
}