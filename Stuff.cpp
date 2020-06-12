#include "Stuff.h"

std::string GetValidString(int _strtype = STR_ENG | STR_RUS | STR_DIGITS | STR_PATH | STR_SUBJ) {
	std::string _input = "";
	//int ready = 0;
	if (_strtype == STR_DIGITS) {
		do {
			CLEAN
				std::getline(std::cin, _input);
			CLEAN
				if (_input.empty()) continue;
			if (_input.find_first_not_of("+-0123456789") == std::string::npos) break;
		} while (87);
		//return _input;
	}
	if (_strtype == STR_ENG) {
		do {
			CLEAN
				std::getline(std::cin, _input);
			CLEAN
				if (_input.empty()) continue;
			if (_input.find_first_not_of("-.abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == std::string::npos) break;
		} while (87);
	}
	if (_strtype == STR_RUS) {
		do {
			CLEAN
				std::getline(std::cin, _input);
			CLEAN
				if (_input.empty()) continue;
			if (_input.find_first_not_of("-.абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ") == std::string::npos) break;
		} while (87);
	}
	if (_strtype == (STR_ENG | STR_RUS)) {
		do {
			CLEAN
				std::getline(std::cin, _input);
			CLEAN
				if (_input.empty()) continue;
			if (_input.find_first_not_of("-.abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZабвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ") == std::string::npos) break;
		} while (87);
	}
	if (_strtype == (STR_ENG | STR_RUS | STR_DIGITS)) {
		do {
			CLEAN
				std::getline(std::cin, _input);
			CLEAN
				if (_input.empty()) continue;
			if (_input.find_first_not_of("-0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZабвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ") == std::string::npos) break;
		} while (87);
	}
	if (_strtype == STR_PATH) {
		do {
			CLEAN
				std::getline(std::cin, _input);
			CLEAN
				if (_input.empty()) continue;
			if (_input.find_first_not_of(".-_0123456789()abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ") == std::string::npos) break;
		} while (87);
	}
	if (_strtype == STR_SUBJ) {
		do {
			CLEAN
				std::getline(std::cin, _input);
			CLEAN
				if (_input.empty()) continue;
			if (_input.find_first_not_of("- .абвгдеёжзийклмнопрстуфхцчшщъыьэюяАБВГДЕЁЖЗИЙКЛМНОПРСТУФХЦЧШЩЪЫЬЭЮЯ") == std::string::npos) break;
		} while (87);
	}
	return _input;
}

Student* InputStudent() {
	std::string name = "", surn = "", patr = "", faculty = "", chair = "", groupname = "", gradebook = "", subjName = "";
	int day = 0, month = 0, year = 0, enroll = 0, n_sessions = 0, n_subjects = 0, subjMark = 0;
	char sex = 'М';
	Student* NewStudent = nullptr;
	Date* dob = nullptr;
	dob = new Date();
	std::cout << "Фамилия: ";
	surn = GetValidString(STR_ENG | STR_RUS);
	std::cout << "Имя: ";
	name = GetValidString(STR_ENG | STR_RUS);
	std::cout << "Отчество: ";
	patr = GetValidString(STR_ENG | STR_RUS);
	while (87) {
		std::cout << "Пол (М/Ж): ";
		sex = GetValidString(STR_RUS)[0];
		if ((sex == 'М') || (sex == 'Ж')) break;
		else std::cout << "Неверный пол. Попробуйте снова." << std::endl;
	}
	while (87) {
		std::cout << "Дата рождения (ДД): ";
		day = stoi(GetValidString(STR_DIGITS).substr(0, 2));
		std::cout << "Дата рождения (ММ): ";
		month = stoi(GetValidString(STR_DIGITS).substr(0, 2));
		std::cout << "Дата рождения (ГГГГ): ";
		year = stoi(GetValidString(STR_DIGITS).substr(0, 4));
		if (dob->ValiDate(day, month, year)) break;
		else std::cout << "Неверная дата рождения. Попробуйте снова." << std::endl;
	}
	while (87) {
		std::cout << "Год поступления: ";
		enroll = stoi(GetValidString(STR_DIGITS).substr(0, 4));
		if ((enroll - 16) > year) break;
		else std::cout << "Неверный год поступления. Проверьте возрастные границы." << std::endl;
	}
	std::cout << "Факультет: ";
	faculty = GetValidString(STR_RUS);
	std::cout << "Кафедра: ";
	chair = GetValidString(STR_RUS | STR_ENG | STR_DIGITS);
	std::cout << "Учебная группа: ";
	groupname = GetValidString(STR_RUS | STR_ENG | STR_DIGITS);
	std::cout << "Номер зачётной книжки: ";
	gradebook = GetValidString(STR_ENG | STR_RUS | STR_DIGITS);
	std::cout << "---------- Ввод данных о сессиях для студента " << name << ' ' << surn << " ----------" << std::endl;
	while (87) {
		std::cout << "Количество сессий (1-9): ";
		n_sessions = stoi(GetValidString(STR_DIGITS).substr(0, 2));
		if ((n_sessions >= 1) && (n_sessions <= 9)) break;
		else std::cout << "Неверное количество сессий. Попробуйте снова." << std::endl;
	}
	Session* Sessions = new Session[n_sessions];
	FORi(0, n_sessions) {
		std::cout << "[сессия " << i + 1 << "] ";
		while (87) {
			std::cout << "Количество предметов в сессии (1-10): ";
			n_subjects = stoi(GetValidString(STR_DIGITS).substr(0, 3));
			if ((n_subjects >= 1) && (n_subjects <= 10)) break;
			else std::cout << "Неверное количество предметов. Попробойте снова." << std::endl;
		}
		Subject* subjects = new Subject[n_subjects];
		FORj(0, n_subjects) {
			std::cout << "[сессия " << i + 1 << "][предмет " << j + 1 << "] название (до 29 символов): ";
			subjName = GetValidString(STR_SUBJ);
			strcpy_s(subjects[j].title, subjName.substr(0, 29).c_str());
			std::cout << "[сессия " << i + 1 << "][предмет " << j + 1 << "] оценка (2-5): ";
			while (87) {
				subjMark = stoi(GetValidString(STR_DIGITS).substr(0, 2));
				if ((subjMark >= 2) && (subjMark <= 5)) break;
				else std::cout << "Неверная оценка. Попробуйте снова.";
			}
			subjects[j].mark = subjMark;
			//Sessions[i].subjects[j] = subjects[j];
			Session s(n_subjects, subjects);
			Sessions[i] = s;
		}
	}
	delete dob;
	dob = new Date(day, month, year);
	NewStudent = new Student(
		name.substr(0, 29).c_str(),
		surn.substr(0, 29).c_str(),
		patr.substr(0, 29).c_str(),
		*dob,
		sex,
		enroll,
		faculty.substr(0, 9).c_str(),
		chair.substr(0, 9).c_str(),
		groupname.substr(0, 14).c_str(),
		gradebook.substr(0, 9).c_str(),
		Sessions,
		n_sessions
	);
	return NewStudent;
}

int FileExists(std::string& _fname) {
	std::ifstream fin(_fname.c_str());
	return fin.good();
}

int CryptExportToFile(ListOfStudents& _list, std::string& _filename) {
	if (_list.IsEmpty()) return 0;
	std::ofstream fout((_filename + ".enc").c_str(), std::ios::out | std::ios::binary);
	if (!fout) { std::cout << "Возникла непредвиденная ошибка при открытии файла. Запись прервана."; return -1; }
	int iStudentsExported = 0;
	Student toExport;
	HCRYPTPROV hProvider;
	HCRYPTKEY hSessionKey;
	HCRYPTHASH hHash;
	DWORD dwDataLen, dwPasswordLen;
	CHAR szPassword[PASSWORD_LEN] = "";
	dwDataLen = sizeof(Student);
	if (!CryptAcquireContext(
		&hProvider,
		NULL,
		NULL,
		PROV_RSA_FULL,
		0
	)) {
		std::cout << "Ошибка во время получения контекста криптопровайдера!" << std::endl;
		return -1;
	}
	std::cout << "Пароль для шифрования файла: ";
	strcpy_s(szPassword, GetValidString(STR_ENG | STR_RUS | STR_DIGITS).substr(0, PASSWORD_LEN - 1).c_str());
	dwPasswordLen = strlen(szPassword);
	if (!CryptCreateHash(
		hProvider,
		CALG_MD5,
		0,
		0,
		&hHash
	)) {
		std::cout << "Ошибка во время генерации хеша пароля!" << std::endl;
		return -1;
	}
	if (!CryptHashData(
		hHash,
		(BYTE*)szPassword,
		dwPasswordLen,
		0
	)) {
		std::cout << "Ошибка во время хеширования пароля!" << std::endl;
		return -1;
	}
	if (!CryptDeriveKey(
		hProvider,
		CALG_RC4,
		hHash,
		CRYPT_EXPORTABLE,
		&hSessionKey
	)) {
		std::cout << "Ошибка во время получения ключа на основе пароля!" << std::endl;
		return -1;
	}
	FORi(0, _list.Length()) {
		toExport = _list[i];
		if (!CryptEncrypt(
			hSessionKey,
			NULL,
			TRUE,
			0,
			(BYTE*)&toExport,
			&dwDataLen,
			dwDataLen
		)) {
			std::cout << "Ошибка во время шифрования студента " << i << std::endl;
			return -1;
		}
		fout.write((char*)&toExport, sizeof(Student));
		iStudentsExported += 1;
	}
	if (hHash)
		if (!(CryptDestroyHash(hHash))) {
			std::cout << "Ошибка во время уничтожения хеша!" << std::endl;
			return -1;
		}
	if (hSessionKey)
		if (!(CryptDestroyKey(hSessionKey))) {
			std::cout << "Ошибка во время уничтожения ключа!" << std::endl;
			return -1;
		}
	if (hProvider)
		if (!(CryptReleaseContext(hProvider, 0))) {
			std::cout << "Ошибка во время освобождения контекста криптопровайдера!" << std::endl;
			return -1;
		}
	fout.close();
	return iStudentsExported;
}

int CryptLoadFromFile(ListOfStudents& _list, std::string& _filename) {
	if (!FileExists(_filename)) {
		std::cout << "Файл " << _filename << " не найден." << std::endl;
		return 0;
	}
	std::ifstream fin(_filename.c_str(), std::ios::in | std::ios::binary);
	if (!fin) { std::cout << "Возникла непредвиденная ошибка при открытии файла. Считывание прервано."; return -1; }
	_list.Reset();
	int iStudentsImported = 0;
	Student fromFile;
	HCRYPTPROV hProvider;
	HCRYPTKEY hSessionKey;
	HCRYPTHASH hHash;
	DWORD dwDataLen, dwPasswordLen;
	CHAR szPassword[PASSWORD_LEN] = "";
	dwDataLen = sizeof(Student);
	if (!CryptAcquireContext(
		&hProvider,
		NULL,
		NULL,
		PROV_RSA_FULL,
		0
	)) {
		std::cout << "Ошибка во время получения контекста криптопровайдера!" << std::endl;
		return -1;
	}
	std::cout << "Пароль для расшифровки файла: ";
	strcpy_s(szPassword, GetValidString(STR_ENG | STR_RUS | STR_DIGITS).substr(0, PASSWORD_LEN - 1).c_str());
	dwPasswordLen = strlen(szPassword);
	if (!CryptCreateHash(
		hProvider,
		CALG_MD5,
		0,
		0,
		&hHash
	)) {
		std::cout << "Ошибка во время генерации хеша пароля!" << std::endl;
		return -1;
	}
	if (!CryptHashData(
		hHash,
		(BYTE*)szPassword,
		dwPasswordLen,
		0
	)) {
		std::cout << "Ошибка во время хеширования пароля!" << std::endl;
		return -1;
	}
	if (!CryptDeriveKey(
		hProvider,
		CALG_RC4,
		hHash,
		CRYPT_EXPORTABLE,
		&hSessionKey
	)) {
		std::cout << "Ошибка во время получения ключа на основе пароля!" << std::endl;
		return -1;
	}
	while (fin.read((char*)&fromFile, sizeof(Student))) {
		if (!CryptDecrypt(
			hSessionKey,
			NULL,
			TRUE,
			0,
			(BYTE*)&fromFile,
			&dwDataLen
		)) {
			std::cout << "Ошибка во время расшифровки студента " << std::endl;
			return -1;
		}
		if (!_list.StudentExists(fromFile)) {
			_list.Append(fromFile);
			iStudentsImported += 1;
		}
	}
	if (hHash)
		if (!(CryptDestroyHash(hHash))) {
			std::cout << "Ошибка во время уничтожения хеша!" << std::endl;
			return -1;
		}
	if (hSessionKey)
		if (!(CryptDestroyKey(hSessionKey))) {
			std::cout << "Ошибка во время уничтожения ключа!" << std::endl;
			return -1;
		}
	if (hProvider)
		if (!(CryptReleaseContext(hProvider, 0))) {
			std::cout << "Ошибка во время освобождения контекста криптопровайдера!" << std::endl;
			return -1;
		}
	fin.close();
	return iStudentsImported;
}