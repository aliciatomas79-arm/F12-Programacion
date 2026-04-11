# definims las variables
estudiante_activo = True
tarea_completa =False

# Probamos la lógica  de las variables
if estudiante_activo and not tarea_completa:
    print("Estado: Registrado en ECFM. Tiene tareas pendientes por resolver.")

#verificamos el tipo de dato de las variables
print(f"El valor {tarea_completa} es de tipo: {type(tarea_completa)}")