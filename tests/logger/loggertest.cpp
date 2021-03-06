#include "logger.h"

int main() {

	Logger& log = Logger::get();

	// Crea si no existe, append si existe
	log.open("event.log");

	//  Ponemos todos los modos de loggeo
	log.toggle(LOG_TYPE::DEBUG, true);
	log.toggle(LOG_TYPE::WARN, true);
	log.toggle(LOG_TYPE::INFO, true);
	log.toggle(LOG_TYPE::ERROR, true);

	// Guardamos un mensaje de cada tipo
	log.msg(LOG_TYPE::WARN, "log de tipo warning");
	log.msg(LOG_TYPE::ERROR, "log de tipo error");
	log.msg(LOG_TYPE::INFO, "log de tipo info");
	log.msg(LOG_TYPE::DEBUG, "log de tipo debug");

	// Desactivamos los modos de loggeo
	log.toggle(LOG_TYPE::DEBUG, false);
	log.toggle(LOG_TYPE::WARN, false);
	log.toggle(LOG_TYPE::INFO, false);
	log.toggle(LOG_TYPE::ERROR, false);

	// Ninguno de estos deberia aparecer
	log.msg(LOG_TYPE::WARN, "NO log de tipo warning");
	log.msg(LOG_TYPE::ERROR, "NO log de tipo error");
	log.msg(LOG_TYPE::INFO, "NO log de tipo info");
	log.msg(LOG_TYPE::DEBUG, "NO log de tipo debug");
	// Log con type invalid
	log.msg(493843, "log random invalid type");


	// Cerramos el log
	log.close();

}
