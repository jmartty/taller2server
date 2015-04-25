# -*- coding: utf-8 -*-
import requests
import unittest
import json


class TestRestApi(unittest.TestCase):
	def __init__(self, *args, **kwargs):
		super(TestRestApi, self).__init__(*args, **kwargs)
		self.__api_base_url = "http://localhost:5000/server"
		self.__user_url = "/Usuario"
		self.__login = "/Login"
		self.__conversation = "/Conversacion"

#Login
#Loguear usuario en el sistema
		
	def test_authentication_fail(self):
		'''Pruebo que falle cuando se loguea un usuario inexistente'''
		user_incorrecto = { "user": "user", "pwd": "1234" }
		user_incorrecto_js = json.dumps(user_incorrecto)
		r = requests.get(self.__api_base_url + self.__login, auth = user_incorrecto_js)
		self.assertEqual(r.status_code, 401)

	def test_authentication_default_user(self):
		'''Pruebo que funcione el login de un usuario existente, con su pass adecuada'''
                user_correcto = { "user": "admin", "pwd": "root" }
                user_correcto_js = json.dumps(user_correcto)
		r = requests.get(self.__api_base_url + self.__login, auth = user_correcto_js)
		self.assertEqual(r.status_code, 201)

	def test_authentication_wrong_pass_fail(self):
		'''Pruebo que falle cuando se loguea un usuario existente, con pass incorrecta'''
                pass_incorrecto = { "user": "admin", "pwd": "1234" }
                pass_incorrecto_js = json.dumps(pass_incorrecto)
		r = requests.get(self.__api_base_url + self.__login, auth = pass_incorrecto_js)
		self.assertEqual(r.status_code, 401)


#Usuario
#Registro de usuarios

	def test_user_add(self):
		'''Pruebo que se cree correctamente un nuevo usuario'''
                user_prueba = "Fulano"
                registro_valido = { "password": "abcde", "nombre": "Fulano", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba, data = registro_valido_js)
		self.assertEqual(r.status_code, 201)

	def test_existing_user_add(self):
		'''Pruebo que falle al crear un usuario que ya existe'''
                user_existente = "admin"
                registro_valido = { "password": "abcde", "nombre": "Admin", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_existente, data = registro_valido_js)
		self.assertEqual(r.status_code, 400)

	def test_long_user_add(self):
		'''Pruebo que falle al crear un usuario que contiene mas de 12 caracteres'''
                user_largo = "Fulano12345678910"
                registro_valido = { "password": "abcde", "nombre": "Admin", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_largo, data = registro_valido_js)
		self.assertEqual(r.status_code, 400)


	def test_not_alphanumeric_user_add(self):
		'''Pruebo que falle al crear un usuario que contiene caracteres no alfaumericos'''
                user_wrong = "Fulano_1?"
                registro_valido = { "password": "abcde", "nombre": "Admin", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_wrong, data = registro_valido_js)
		self.assertEqual(r.status_code, 400)


        def test_empty_user_add(self):
		'''Pruebo que falle al crear un usuario sin caracteres'''
                user_wrong = ""
                registro_valido = { "password": "abcde", "nombre": "Admin", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_wrong, data = registro_valido_js)
		self.assertEqual(r.status_code, 400)


        def test_empty_pass_user_add(self):
		'''Pruebo que falle al crear un usuario con contrasenia sin caracteres'''
                user_valido = "Mengano"
                registro_invalido = { "password": "", "nombre": "Admin", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_invalido_js = json.dumps(registro_invalido)
		r = requests.post(self.__api_base_url + self.__user_url + user_wrong, data = registro_invalido_js)
		self.assertEqual(r.status_code, 400)


        def test_empty_name_user_add(self):
		'''Pruebo que falle al crear un usuario con nombre sin caracteres'''
                user_valido = "Mengano"
                registro_invalido = { "password": "abcde12", "nombre": "", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_invalido_js = json.dumps(registro_invalido)
		r = requests.post(self.__api_base_url + self.__user_url + user_wrong, data = registro_invalido_js)
		self.assertEqual(r.status_code, 400)


#Solicitar lista de usuarios

	def test_get_user_collection(self):
                '''Pruebo obtener lista de usuarios con token correcto'''
                user_prueba = "Fulano"
                registro_valido = { "password": "abcde", "nombre": "Fulano", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba, data = registro_valido_js)
		token = r.json()
                r = requests.get(self.__api_base_url + self.__user_url, params = token["token"])
		users = r.json()
		self.assertEqual(users.has_key('Fulano'), True)
		self.assertEqual(r.status_code, 200)

	def test_get_user_collection_wrong_token(self):
                '''Pruebo obtener lista de usuarios con token incorrecto'''
                r = requests.get(self.__api_base_url + self.__user_url, params = "unTokenIncorrecto")
		self.assertEqual(r.status_code, 401)



#Solicitar perfil de usuario

	def test_get_user_profile(self):
                '''Pruebo obtener perfil de usuario'''
                user_prueba = "Fulano"
                registro_valido = { "password": "abcde", "nombre": "Fulano", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba, data = registro_valido_js)
		token = r.json()
                r = requests.get(self.__api_base_url + self.__user_url + user_prueba, params = token["token"])
		self.assertEqual(r.status_code, 200)

	def test_get_user_profile_wrong_token(self):
                '''Pruebo obtener perfil de usuario con token incorrecto'''
                user_prueba = "Fulano"
                registro_valido = { "password": "abcde", "nombre": "Fulano", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba, data = registro_valido_js)
		token = r.json()
                r = requests.get(self.__api_base_url + self.__user_url + user_prueba, params = "unTokenIncorrecto")
		self.assertEqual(r.status_code, 401)

	def test_get_user_profile_wrong_user(self):
                '''Pruebo obtener perfil de usuario con usuario incorrecto'''
                user_prueba = "Fulano"
                registro_valido = { "password": "abcde", "nombre": "Fulano", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba, data = registro_valido_js)
		token = r.json()
                r = requests.get(self.__api_base_url + self.__user_url + "UserIncorrecto", params = token["token"])
		self.assertEqual(r.status_code, 401)


#Modificar usuario

	def test_modify_user(self):
                '''Pruebo modificar usuario'''
                user_prueba = "Fulano"
                registro_valido = { "password": "abcde", "nombre": "Fulano", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba, data = registro_valido_js)
		token = r.json()
                datos = { "token": token["token"],"nombre": "Otronombre","foto": "otrafoto","ubicacion": "unaubicacion"}
                datos_js = json.dumps(datos)
		r = requests.put(self.__api_base_url + self.__user_url + user_prueba, data = datos_js)
		self.assertEqual(r.status_code, 201)

	def test_modify_user_wrong_token(self):
                '''Pruebo modificar usuario con token incorrecto'''
                user_prueba = "Fulano"
                registro_valido = { "password": "abcde", "nombre": "Fulano", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba, data = registro_valido_js)
		token = r.json()
                datos = { "token": "tokenIncorrecto","nombre": "Otronombre","foto": "otrafoto","ubicación": "unaubicacion"}
                datos_js = json.dumps(datos)
		r = requests.put(self.__api_base_url + self.__user_url + user_prueba, data = datos_js)
		self.assertEqual(r.status_code, 401)


	def test_modify_user_wrong_user(self):
                '''Pruebo modificar usuario con usuario invalido'''
                user_prueba = "Fulano"
                registro_valido = { "password": "abcde", "nombre": "Fulano", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba, data = registro_valido_js)
		token = r.json()
                datos = { "token": token["token"],"nombre": "Otronombre","foto": "otrafoto","ubicación": "unaubicacion"}
                datos_js = json.dumps(datos)
		r = requests.put(self.__api_base_url + self.__user_url + "UsuarioInvalido", data = datos_js)
		self.assertEqual(r.status_code, 401)

	def test_modify_user_wrong_name(self):
                '''Pruebo modificar usuario con nombre invalido'''
                user_prueba = "Fulano"
                registro_valido = { "password": "abcde", "nombre": "Fulano", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba, data = registro_valido_js)
		token = r.json()
                datos = { "token": token["token"],"nombre": 123456,"foto": "otrafoto","ubicación": "unaubicacion"}
                datos_js = json.dumps(datos)
		r = requests.put(self.__api_base_url + self.__user_url + user_prueba, data = datos_js)
		self.assertEqual(r.status_code, 400)


#Conversacion
#Solicitar conversación anterior entre usuario <user1> y <user2>

	def test_get_messages(self):
                '''Pruebo obtener conversacion'''
                #Registro User1
                user_prueba = "Fulanito"
                registro_valido = { "password": "abcde", "nombre": "Fulanito", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba, data = registro_valido_js)
		token1 = r.json()
		#Registro User2
                user_prueba2 = "Menganito"
                registro_valido = { "password": "abcde", "nombre": "Menganito", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba2, data = registro_valido_js)
		token2 = r.json()

		#Envio un mensaje
		mensaje = {"token": token1["token"],"mensaje" : "hola"}
		mensaje_js = json.dumps(mensaje)
		r = requests.post(self.__api_base_url + self.__conversation + "Fulanito.Menganito", data = mensaje_js)

		r = requests.get(self.__api_base_url + self.__conversation + "Fulanito.Menganito", params = token1["token"])
		mensajes = r.json()
		self.assertEqual(r.status_code, 200)
		self.assertEqual(mensajes["mensajes"], ["hola"])

	def test_get_messages_wrong_token(self):
                '''Pruebo obtener conversacion con token incorrecto'''
                #Registro User1
                user_prueba = "Fulanito"
                registro_valido = { "password": "abcde", "nombre": "Fulanito", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba, data = registro_valido_js)
		token1 = r.json()
		#Registro User2
                user_prueba2 = "Menganito"
                registro_valido = { "password": "abcde", "nombre": "Menganito", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba2, data = registro_valido_js)
		token2 = r.json()

		#Envio un mensaje
		mensaje = {"token": token1["token"],"mensaje" : "hola"}
		mensaje_js = json.dumps(mensaje)
		r = requests.post(self.__api_base_url + self.__conversation + "Fulanito.Menganito", data = mensaje_js)

		r = requests.get(self.__api_base_url + self.__conversation + "Fulanito.Menganito", params = "TokenIncorrecto")
		self.assertEqual(r.status_code, 401)

	def test_get_messages_wrong_user(self):
                '''Pruebo obtener conversacion con user incorrecto'''
                #Registro User1
                user_prueba = "Fulanito"
                registro_valido = { "password": "abcde", "nombre": "Fulanito", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba, data = registro_valido_js)
		token1 = r.json()
		#Registro User2
                user_prueba2 = "Menganito"
                registro_valido = { "password": "abcde", "nombre": "Menganito", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba2, data = registro_valido_js)
		token2 = r.json()

		#Envio un mensaje
		mensaje = {"token": token1["token"],"mensaje" : "hola"}
		mensaje_js = json.dumps(mensaje)
		r = requests.post(self.__api_base_url + self.__conversation + "Fulanito.Menganito", data = mensaje_js)

		r = requests.get(self.__api_base_url + self.__conversation + "UserIncorrecto.Menganito", params = token1["token"])
		self.assertEqual(r.status_code, 401)

#Enviar mensaje de usuario <user1> a <user2>

	def test_send_message(self):
                '''Pruebo el envio de un mensaje entre un usuario y otro'''
                #Registro User1
                user_prueba = "Fulanito"
                registro_valido = { "password": "abcde", "nombre": "Fulanito", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba, data = registro_valido_js)
		token1 = r.json()
		#Registro User2
                user_prueba2 = "Menganito"
                registro_valido = { "password": "abcde", "nombre": "Menganito", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba2, data = registro_valido_js)
		token2 = r.json()

		mensaje = {"token": token1["token"],"mensaje" : "hola"}
		mensaje_js = json.dumps(mensaje)

		r = requests.post(self.__api_base_url + self.__conversation + "Fulanito.Menganito", data = mensaje_js)
		self.assertEqual(r.status_code, 201)

	def test_send_message_wrong_token(self):
                '''Pruebo el envio de un mensaje entre un usuario y otro, con token incorrecto'''
                #Registro User1
                user_prueba = "Fulanito"
                registro_valido = { "password": "abcde", "nombre": "Fulanito", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba, data = registro_valido_js)
		token1 = r.json()
		#Registro User2
                user_prueba2 = "Menganito"
                registro_valido = { "password": "abcde", "nombre": "Menganito", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba2, data = registro_valido_js)
		token2 = r.json()

		mensaje = {"token": "tokenIncorrecto","mensaje" : "hola"}
		mensaje_js = json.dumps(mensaje)

		r = requests.post(self.__api_base_url + self.__conversation + "Fulanito.Menganito", data = mensaje_js)
		self.assertEqual(r.status_code, 401)


	def test_send_message_wrong_user(self):
                '''Pruebo el envio de un mensaje entre un usuario y otro, con usuario invalido'''
                #Registro User1
                user_prueba = "Fulanito"
                registro_valido = { "password": "abcde", "nombre": "Fulanito", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba, data = registro_valido_js)
		token1 = r.json()
		#Registro User2
                user_prueba2 = "Menganito"
                registro_valido = { "password": "abcde", "nombre": "Menganito", "foto": "mifoto", "ubicación": "miubicacion"}
                registro_valido_js = json.dumps(registro_valido)
		r = requests.post(self.__api_base_url + self.__user_url + user_prueba2, data = registro_valido_js)
		token2 = r.json()

		mensaje = {"token": token1["token"],"mensaje" : "hola"}
		mensaje_js = json.dumps(mensaje)

		r = requests.post(self.__api_base_url + self.__conversation + "Fulanito.UsuarioIncorrecto", data = mensaje_js)
		self.assertEqual(r.status_code, 401)

