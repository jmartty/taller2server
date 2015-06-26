# -*- coding: utf-8 -*-
import requests
import unittest
import json


class TestRestApi(unittest.TestCase):
	def __init__(self, *args, **kwargs):
		super(TestRestApi, self).__init__(*args, **kwargs)
		self.__api_base_url = "http://localhost:5000"
		self.__user_url = "/usuario/"
		self.__ruser = "?r_user="
		self.__token = "&token="
		self.__pass = "&password="
		self.__users_url = "/usuarios"
		self.__login = "/login"
		self.__conversation = "/conversacion/"
		self.__broadcast = "/broadcast"
                self.__lines = "&lines="



#Usuario
#Registro de usuarios

	def test_1user_add(self):
		'''Pruebo que se cree correctamente un nuevo usuario'''
                user_prueba = "Fulano"
                registro_valido = { "id": "Fulano", "password": "abcde", "nombre": "Fulano", "foto": "mifoto", "ubicacion": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba, data = registro_valido_js)
		self.assertEqual(r.status_code, 201)


	def test_2existing_user_add(self):
		'''Pruebo que falle al crear un usuario que ya existe'''
                user_existente = "Fulano"
                registro_valido = { "password": "abcde", "nombre": "Admin", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_existente, data = registro_valido_js)
		self.assertEqual(r.status_code, 401)

	def test_3long_user_add(self):
		'''Pruebo que falle al crear un usuario que contiene mas de 12 caracteres'''
                user_largo = "Fulano12345678910"
                registro_valido = { "password": "abcde", "nombre": "Admin", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_largo, data = registro_valido_js)
		self.assertEqual(r.status_code, 401)



        def test_5empty_user_add(self):
		'''Pruebo que falle al crear un usuario sin caracteres'''
                user_wrong = ""
                registro_valido = { "password": "abcde", "nombre": "Admin", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_wrong, data = registro_valido_js)
		self.assertEqual(r.status_code, 401)


        def test_6empty_pass_user_add(self):
		'''Pruebo que falle al crear un usuario con contrasenia sin caracteres'''
                user_valido = "Mengano"
                registro_invalido = { "password": "", "nombre": "Admin", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_invalido_js = json.dumps(registro_invalido)
		r = requests.post(self.__api_base_url + self.__user_url + user_valido, data = registro_invalido_js)
		self.assertEqual(r.status_code, 401)


        def test_7empty_name_user_add(self):
		'''Pruebo que falle al crear un usuario con nombre sin caracteres'''
                user_valido = "Mengano"
                registro_invalido = { "password": "abcde12", "nombre": "", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_invalido_js = json.dumps(registro_invalido)
		r = requests.post(self.__api_base_url + self.__user_url + user_valido, data = registro_invalido_js)
		self.assertEqual(r.status_code, 401)


#Login
#Loguear usuario en el sistema
		
	def test_8authentication_fail(self):
		'''Pruebo que falle cuando se loguea un usuario inexistente'''
		user_incorrecto = { "id": "user", "password": "1234" }
		user_incorrecto_js = json.dumps(user_incorrecto)
		r = requests.post(self.__api_base_url + self.__login, data = user_incorrecto_js)
		self.assertEqual(r.status_code, 401)

	def test_9authentication_default_user(self):
		'''Pruebo que funcione el login de un usuario existente, con su pass adecuada'''
                user_correcto = { "id": "Fulano", "password": "abcde" }
                user_correcto_js = json.dumps(user_correcto)
		r = requests.post(self.__api_base_url + self.__login, data = user_correcto_js)
		self.assertEqual(r.status_code, 201)

	def test_91authentication_wrong_pass_fail(self):
		'''Pruebo que falle cuando se loguea un usuario existente, con pass incorrecta'''
                pass_incorrecto = { "id": "admin", "password": "1234" }
                pass_incorrecto_js = json.dumps(pass_incorrecto)
		r = requests.post(self.__api_base_url + self.__login, data = pass_incorrecto_js)
		self.assertEqual(r.status_code, 401)

#Solicitar lista de usuarios

	def test_92get_user_collection(self):
                '''Pruebo obtener lista de usuarios con token correcto'''
                user_prueba = "Wulano"
                registro_valido = { "password": "abcde", "nombre": "Wulano", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba, data = registro_valido_js)
		user_correcto = { "id": "Wulano", "password": "abcde" }
                user_correcto_js = json.dumps(user_correcto)
		r2 = requests.post(self.__api_base_url + self.__login, data = user_correcto_js)
		token = r2.json()
		token["token"] = token["token"][0:16]
                r3 = requests.get(self.__api_base_url + self.__users_url + self.__ruser + "Wulano" + self.__token + token["token"])
                self.assertEqual(r3.status_code, 200)

	def test_93get_user_collection_wrong_token(self):
                '''Pruebo obtener lista de usuarios con token incorrecto'''
                r = requests.get(self.__api_base_url + self.__users_url + self.__ruser + "Fulano" + self.__token + "unTokenIncorrecto")
		self.assertEqual(r.status_code, 401)



#Solicitar perfil de usuario

	def test_94get_user_profile(self):
                '''Pruebo obtener perfil de usuario'''
                user_prueba = "Fulano2"
                registro_valido = { "password": "abcde", "nombre": "Fulano2", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba, data = registro_valido_js)
		user_correcto = { "id": "Fulano2", "password": "abcde" }
                user_correcto_js = json.dumps(user_correcto)
		r2 = requests.post(self.__api_base_url + self.__login, data = user_correcto_js)
		token = r2.json()
		token["token"] = token["token"][0:16]
                r = requests.get(self.__api_base_url + self.__user_url + user_prueba + self.__ruser + "Fulano2" + self.__token + token["token"])
		self.assertEqual(r.status_code, 200)

	def test_95get_user_profile_wrong_token(self):
                '''Pruebo obtener perfil de usuario con token incorrecto'''
                user_prueba = "Fulano3"
                registro_valido = { "password": "abcde", "nombre": "Fulano3", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba, data = registro_valido_js)
		user_correcto = { "id": "Fulano3", "password": "abcde" }
                user_correcto_js = json.dumps(user_correcto)
		r2 = requests.post(self.__api_base_url + self.__login, data = user_correcto_js)
		token = r2.json()
		token["token"] = token["token"][0:16]
                r = requests.get(self.__api_base_url + self.__user_url + user_prueba + self.__ruser + "Fulano3" + self.__token + "unTokenIncorrecto")
		self.assertEqual(r.status_code, 401)

	def test_96get_user_profile_wrong_user(self):
                '''Pruebo obtener perfil de usuario con usuario incorrecto'''
                user_prueba = "Fulano4"
                registro_valido = { "password": "abcde", "nombre": "Fulano4", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba, data = registro_valido_js)
		user_correcto = { "id": "Fulano4", "password": "abcde" }
                user_correcto_js = json.dumps(user_correcto)
		r2 = requests.post(self.__api_base_url + self.__login, data = user_correcto_js)
		token = r2.json()
		token["token"] = token["token"][0:16]
                r = requests.get(self.__api_base_url + self.__user_url + user_prueba + self.__ruser + "UserIncorrecto" + self.__token + token["token"])
		self.assertEqual(r.status_code, 401)


#Modificar usuario

	def test_97modify_user(self):
                '''Pruebo modificar usuario'''
                user_prueba = "Fulano5"
                registro_valido = { "password": "abcde", "nombre": "Fulano5", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba, data = registro_valido_js)
		user_correcto = { "id": "Fulano5", "password": "abcde" }
                user_correcto_js = json.dumps(user_correcto)
		r2 = requests.post(self.__api_base_url + self.__login, data = user_correcto_js)
		token = r2.json()
		token["token"] = token["token"][0:16]
                datos = {"nombre": "Otronombre","password": "abcde","foto": "otrafoto","ubicacion": "unaubicacion"}
                datos_js = json.dumps(datos)
		r = requests.put(self.__api_base_url + self.__user_url + user_prueba + self.__ruser + "Fulano5" + self.__token + token["token"]+self.__pass + "abcde", data = datos_js)
		self.assertEqual(r.status_code, 201)


	def test_99modify_user_wrong_user(self):
                '''Pruebo modificar usuario con usuario invalido'''
                user_prueba = "Fulano7"
                registro_valido = { "password": "abcde", "nombre": "Fulano7", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba, data = registro_valido_js)
		user_correcto = { "id": "Fulano7", "password": "abcde" }
                user_correcto_js = json.dumps(user_correcto)
		r2 = requests.post(self.__api_base_url + self.__login, data = user_correcto_js)
		token = r2.json()
		token["token"] = token["token"][0:16]
                datos = {"nombre": "Otronombre","password": "abcde","foto": "otrafoto","ubicación": "unaubicacion"}
                datos_js = json.dumps(datos)
		r = requests.put(self.__api_base_url + self.__user_url + "UsuarioInvalido" + self.__ruser + "Fulano7" + self.__token + token["token"]+self.__pass + "abcde", data = datos_js)
		self.assertEqual(r.status_code, 401)

	def test_991modify_user_wrong_name(self):
                '''Pruebo modificar usuario con nombre invalido'''
                user_prueba = "Fulano8"
                registro_valido = { "password": "abcde", "nombre": "Fulano8", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba, data = registro_valido_js)
		user_correcto = { "id": "Fulano8", "password": "abcde" }
                user_correcto_js = json.dumps(user_correcto)
		r2 = requests.post(self.__api_base_url + self.__login, data = user_correcto_js)
		token = r2.json()
		token["token"] = token["token"][0:16]
                datos = {"nombre": "aaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa","password": "abcde","foto": "otrafoto","ubicación": "unaubicacion"}
                datos_js = json.dumps(datos)
		r = requests.put(self.__api_base_url + self.__user_url + user_prueba + self.__ruser + "Fulano8" + self.__token + token["token"]+self.__pass + "abcde", data = datos_js)
		self.assertEqual(r.status_code, 401)


#Conversacion
#Solicitar conversación anterior entre usuario <user1> y <user2>

	def test_992get_messages(self):
                '''Pruebo obtener conversacion'''
                #Registro User1
                user_prueba = "Fulanito"
                registro_valido = { "password": "abcde", "nombre": "Fulanito", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba, data = registro_valido_js)

		#Registro User2
                user_prueba2 = "Menito"
                registro_valido2 = { "password": "abcdef", "nombre": "Menito", "foto": "mifotoo", "ubicación": "miubicacionn"}
                registro_valido2_js = json.dumps(registro_valido2)
		r2 = requests.post(self.__api_base_url + self.__user_url + user_prueba2, data = registro_valido2_js)

                #Login
		user_correcto = { "id": "Fulanito", "password": "abcde" }
		user_correcto_js = json.dumps(user_correcto)
		r3 = requests.post(self.__api_base_url + self.__login, data = user_correcto_js)
		token1 = r3.json()
		token1["token"] = token1["token"][0:16]

		user_correcto2 = { "id": "Menito", "password": "abcdef" }
		user_correcto2_js = json.dumps(user_correcto2)
		r4 = requests.post(self.__api_base_url + self.__login, data = user_correcto2_js)
		token2 = r4.json()
		token2["token"] = token2["token"][0:16]
		#Envio un mensaje
		mensaje = {"mensaje" : "hola"}
		mensaje_js = json.dumps(mensaje)
		r5 = requests.post(self.__api_base_url + self.__conversation + "Menito" + self.__ruser + "Fulanito" + self.__token + token1["token"], data = mensaje_js)

		r6 = requests.get(self.__api_base_url + self.__conversation + "Menito" + self.__ruser + "Fulanito" + self.__token + token1["token"])
                print r6
                self.assertEqual(r6.status_code, 200)

	def test_993get_messages_wrong_token(self):
                '''Pruebo obtener conversacion con token incorrecto'''
                #Registro User1
                user_prueba = "Fulanit1"
                registro_valido = { "password": "abcde", "nombre": "Fulanit1", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba, data = registro_valido_js)
		#Registro User2
                user_prueba2 = "Menito2"
                registro_valido2 = { "password": "abcde", "nombre": "Menganito2", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido2_js = json.dumps(registro_valido)
		r2 = requests.post(self.__api_base_url + self.__user_url + user_prueba2, data = registro_valido2_js)

                #Login
		user_correcto = { "id": "Fulanit1", "password": "abcde" }
		user_correcto_js = json.dumps(user_correcto)
		r3 = requests.post(self.__api_base_url + self.__login, data = user_correcto_js)
		token1 = r3.json()
		token1["token"] = token1["token"][0:16]

		user_correcto2 = { "id": "Menito2", "password": "abcde" }
		user_correcto2_js = json.dumps(user_correcto2)
		r4 = requests.post(self.__api_base_url + self.__login, data = user_correcto2_js)
		token2 = r4.json()
		token2["token"] = token2["token"][0:16]

		
		#Envio un mensaje
		mensaje = {"mensaje" : "hola"}
		mensaje_js = json.dumps(mensaje)
		r5 = requests.post(self.__api_base_url + self.__conversation + "Menito2" + self.__ruser + "Fulanit1" + self.__token + token1["token"], data = mensaje_js)

		r6 = requests.get(self.__api_base_url + self.__conversation + "Menito2"+ self.__ruser + "Fulanit1" + self.__token + "TokenIncorrecto")
		self.assertEqual(r6.status_code, 401)

	def test_994get_messages_wrong_user(self):
                '''Pruebo obtener conversacion con user incorrecto'''
                #Registro User1
                user_prueba = "Fulanit3"
                registro_valido = { "password": "abcde", "nombre": "Fulanit3", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba, data = registro_valido_js)
		#Registro User2
                user_prueba2 = "Menito3"
                registro_valido = { "password": "abcde", "nombre": "Menganito3", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba2, data = registro_valido_js)

		#Login
		user_correcto = { "id": "Fulanit3", "password": "abcde" }
		user_correcto_js = json.dumps(user_correcto)
		r3 = requests.post(self.__api_base_url + self.__login, data = user_correcto_js)
		token1 = r3.json()
		token1["token"] = token1["token"][0:16]

		user_correcto2 = { "id": "Menito3", "password": "abcde" }
		user_correcto2_js = json.dumps(user_correcto2)
		r4 = requests.post(self.__api_base_url + self.__login, data = user_correcto2_js)
		token2 = r4.json()
		token2["token"] = token2["token"][0:16]

		#Envio un mensaje
		mensaje = {"mensaje" : "hola"}
		mensaje_js = json.dumps(mensaje)
		r5 = requests.post(self.__api_base_url + self.__conversation + "Menito3" + self.__ruser + "Fulanit3" + self.__token + token1["token"], data = mensaje_js)

		r6 = requests.get(self.__api_base_url + self.__conversation + "Menito3" + self.__ruser + "UserIncorrecto" + self.__token + token1["token"])
		self.assertEqual(r6.status_code, 401)

#Enviar mensaje de usuario <user1> a <user2>

	def test_995send_message(self):
                '''Pruebo el envio de un mensaje entre un usuario y otro'''
                #Registro User1
                user_prueba = "Fulanit4"
                registro_valido = { "password": "abcde", "nombre": "Fulanit4", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba, data = registro_valido_js)
		#Registro User2
                user_prueba2 = "Menito4"
                registro_valido = { "password": "abcde", "nombre": "Menganito4", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba2, data = registro_valido_js)

		#Login
		user_correcto = { "id": "Fulanit4", "password": "abcde" }
		user_correcto_js = json.dumps(user_correcto)
		r3 = requests.post(self.__api_base_url + self.__login, data = user_correcto_js)
		token1 = r3.json()
		token1["token"] = token1["token"][0:16]

		user_correcto2 = { "id": "Menito4", "password": "abcde" }
		user_correcto2_js = json.dumps(user_correcto2)
		r4 = requests.post(self.__api_base_url + self.__login, data = user_correcto2_js)
		token2 = r4.json()
		token2["token"] = token2["token"][0:16]
		
		mensaje = {"mensaje" : "hola"}
		mensaje_js = json.dumps(mensaje)

		r = requests.post(self.__api_base_url + self.__conversation + "Menito4" + self.__ruser + "Fulanit4" + self.__token + token1["token"], data = mensaje_js)
		self.assertEqual(r.status_code, 201)

	def test_996send_message_wrong_token(self):
                '''Pruebo el envio de un mensaje entre un usuario y otro, con token incorrecto'''
                #Registro User1
                user_prueba = "Fulanit5"
                registro_valido = { "password": "abcde", "nombre": "Fulanito5", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba, data = registro_valido_js)
		#Registro User2
                user_prueba2 = "Menito5"
                registro_valido = { "password": "abcde", "nombre": "Menganito5", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba2, data = registro_valido_js)

		#Login
		user_correcto = { "id": "Fulanit5", "password": "abcde" }
		user_correcto_js = json.dumps(user_correcto)
		r3 = requests.post(self.__api_base_url + self.__login, data = user_correcto_js)
		token1 = r3.json()
		token1["token"] = token1["token"][0:16]

		user_correcto2 = { "id": "Menito5", "password": "abcde" }
		user_correcto2_js = json.dumps(user_correcto2)
		r4 = requests.post(self.__api_base_url + self.__login, data = user_correcto2_js)
		token2 = r4.json()
		token2["token"] = token2["token"][0:16]

		mensaje = {"mensaje" : "hola"}
		mensaje_js = json.dumps(mensaje)

		r = requests.post(self.__api_base_url + self.__conversation + "Menito5"+ self.__ruser + "Fulanit5" + self.__token + "tokenInvalido", data = mensaje_js)
		self.assertEqual(r.status_code, 401)


	def test_997send_message_wrong_user(self):
                '''Pruebo el envio de un mensaje entre un usuario y otro, con usuario invalido'''
                #Registro User1
                user_prueba = "Fulanit6"
                registro_valido = { "password": "abcde", "nombre": "Fulanito6", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba, data = registro_valido_js)
		#Registro User2
                user_prueba2 = "Menito6"
                registro_valido = { "password": "abcde", "nombre": "Menganito6", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba2, data = registro_valido_js)

		#Login
		user_correcto = { "id": "Fulanit6", "password": "abcde" }
		user_correcto_js = json.dumps(user_correcto)
		r3 = requests.post(self.__api_base_url + self.__login, data = user_correcto_js)
		token1 = r3.json()
		token1["token"] = token1["token"][0:16]

		user_correcto2 = { "id": "Menito6", "password": "abcde" }
		user_correcto2_js = json.dumps(user_correcto2)
		r4 = requests.post(self.__api_base_url + self.__login, data = user_correcto2_js)
		token2 = r4.json()
		token2["token"] = token2["token"][0:16]

		mensaje = {"mensaje" : "hola"}
		mensaje_js = json.dumps(mensaje)

		r = requests.post(self.__api_base_url + self.__conversation + "sUsuarioIncorrecto"+ self.__ruser + "Fulanit6" + self.__token + token1["token"], data = mensaje_js)
		self.assertEqual(r.status_code, 401)


# Broadcast

	def test_998get_broadcast(self):
                '''Pruebo el envio de un mensaje entre un usuario y otro'''
                #Registro User1
                user_prueba = "John"
                registro_valido = { "password": "abcde", "nombre": "Fulanit4", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba, data = registro_valido_js)
		#Registro User2
                user_prueba2 = "Paul"
                registro_valido = { "password": "abcde", "nombre": "Menganito4", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba2, data = registro_valido_js)

		#Login
		user_correcto = { "id": "John", "password": "abcde" }
		user_correcto_js = json.dumps(user_correcto)
		r3 = requests.post(self.__api_base_url + self.__login, data = user_correcto_js)
		token1 = r3.json()
		token1["token"] = token1["token"][0:16]

		user_correcto2 = { "id": "Paul", "password": "abcde" }
		user_correcto2_js = json.dumps(user_correcto2)
		r4 = requests.post(self.__api_base_url + self.__login, data = user_correcto2_js)
		token2 = r4.json()
		token2["token"] = token2["token"][0:16]
		
		mensaje = {"mensaje" : "hola"}
		mensaje_js = json.dumps(mensaje)

		r = requests.post(self.__api_base_url + self.__conversation + "Paul" + self.__ruser + "John" + self.__token + token1["token"], data = mensaje_js)

                r = requests.get(self.__api_base_url + self.__broadcast + self.__ruser + "John" + self.__token + token1["token"] + self.__lines + "1")
                

		self.assertEqual(r.status_code, 200)


	def test_999post_broadcast(self):
                '''Pruebo el envio de un mensaje entre un usuario y otro'''
                #Registro User1
                user_prueba = "John"
                registro_valido = { "password": "abcde", "nombre": "Fulanit4", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba, data = registro_valido_js)
		#Registro User2
                user_prueba2 = "Paul"
                registro_valido = { "password": "abcde", "nombre": "Menganito4", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba2, data = registro_valido_js)

		#Login
		user_correcto = { "id": "John", "password": "abcde" }
		user_correcto_js = json.dumps(user_correcto)
		r3 = requests.post(self.__api_base_url + self.__login, data = user_correcto_js)
		token1 = r3.json()
		token1["token"] = token1["token"][0:16]

		user_correcto2 = { "id": "Paul", "password": "abcde" }
		user_correcto2_js = json.dumps(user_correcto2)
		r4 = requests.post(self.__api_base_url + self.__login, data = user_correcto2_js)
		token2 = r4.json()
		token2["token"] = token2["token"][0:16]
		
		mensaje = {"mensaje" : "hola"}
		mensaje_js = json.dumps(mensaje)

		r = requests.post(self.__api_base_url + self.__conversation + "Paul" + self.__ruser + "John" + self.__token + token1["token"], data = mensaje_js)

                mensaje = {"mensaje" : "hola"}
		mensaje_js = json.dumps(mensaje)

                r = requests.post(self.__api_base_url + self.__broadcast + self.__ruser + "John" + self.__token + token1["token"],data = mensaje_js)
		self.assertEqual(r.status_code, 201)
