function changeColor(){

	

    var borderRed = document.getElementById('borderR').value || 0;
	var borderGreen = document.getElementById('borderG').value || 0;
	var borderBlue = document.getElementById('borderB').value || 0;
	
	var border_width = document.getElementById('border_width').value || 1;

	var backgroundRed = document.getElementById('backgroundR').value || 0;
	var backgroundGreen = document.getElementById('backgroundG').value || 0;
	var backgroundBlue = document.getElementById('backgroundB').value || 0;
    
	var para = document.getElementById('paragraph');

    para.style.borderColor = `rgb(${borderRed},${borderGreen},${borderBlue})`;
    para.style.borderWidth = `${border_width}px`;
    para.style.backgroundColor = `rgb(${backgroundRed},${backgroundGreen},${backgroundBlue})`;
}

function verify(){
	var pswd1 = document.getElementById('first').value;
	var pswd2 = document.getElementById('second').value;

	if (pswd1.length <8 ){
		alert("The length of the first password is less than 8 characters")
	}else if (pswd2.length <8){
		alert("The length of the second password is less than 8 characters")
	}else if (pswd1 != pswd2){
		alert("The passwords don't match")
	}else{
		alert("The passwords are right")
	}
}