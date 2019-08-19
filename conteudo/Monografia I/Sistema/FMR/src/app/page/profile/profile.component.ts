import { Component, OnInit } from '@angular/core';
import * as CanvasJS from '../../../assets/js/canvasjs.min';
import { UserService } from 'src/app/service/user.service';

@Component({
  selector: 'app-profile',
  templateUrl: './profile.component.html',
  styleUrls: ['./profile.component.css']
})
export class ProfileComponent implements OnInit {

  profile = {
    email: "marcos.rodriiigues@gmail.com",
    tipo: "Estudante",
    universidade: "UFOP - Federal de Ouro Preto"
  }

  data = [
    { y: 52, name: "Abertura para o novo" },
    { y: 68, name: "Realização" },
    { y: 40, name: "Extroversão" },
    { y: 35, name: "Socialização" },
    { y: 75, name: "Neuroticismo" },
  ];

  constructor(private _userService : UserService) { }

  ngOnInit() {
    this._userService.checkCredentials();
    this._userService.me().subscribe(data => {
      console.log(data);
    }, err => {
      console.log(err);
    })
    this.initializeChart('chart');
  }

  initializeChart(id) {
    let chart = new CanvasJS.Chart(id, {
      theme: "light2",
      animationEnabled: true,
      exportEnabled: true,
      title:{
        text: "Personalidade"
      },
      data: [{
        type: "pie",
        showInLegend: true,
        toolTipContent: "<b>{name}</b>: {y} (#percent%)",
        indexLabel: "{name} - #percent%",
        dataPoints: this.data,
      }]
    });
    chart.render();
  }

}
