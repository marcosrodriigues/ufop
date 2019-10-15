import { Component, OnInit } from '@angular/core';
import { ActivatedRoute } from '@angular/router';
import * as CanvasJS from '../../../assets/js/canvasjs.min';
import { RepublicaService } from 'src/app/service/republica.service';

@Component({
  selector: 'app-republic-detail',
  templateUrl: './republic-detail.component.html',
  styleUrls: ['./republic-detail.component.css']
})
export class RepublicDetailComponent implements OnInit {

  rep: any = {}
  id: any = 0;

  data = [
    { y: 52, label: "Abertura para o novo" },
    { y: 68, label: "Realização" },
    { y: 40, label: "Extroversão" },
    { y: 35, label: "Socialização" },
    { y: 75, label: "Neuroticismo" },
  ];

  constructor(private router: ActivatedRoute, private _repService : RepublicaService) { 
    this.router.paramMap.subscribe(params => {
      this.id = params.get("id");
    })
  }

  ngOnInit() {
      this.initRep();
  }

  initRep() {
    this._repService.findOne(this.id).subscribe(data => {
      this.rep = data;
      console.log(this.rep);

      this.data[0].y = this.rep.perfil.personalidade.abertura;
      this.data[1].y = this.rep.perfil.personalidade.concordancia;
      this.data[2].y = this.rep.perfil.personalidade.consciencia;
      this.data[3].y = this.rep.perfil.personalidade.extroversao;
      this.data[4].y = this.rep.perfil.personalidade.neuroticismo;

      this.initializeChart('chart');
    });
  }

  initializeChart(id) {
    let chart = new CanvasJS.Chart(id, {
      theme: "light2",
      animationEnabled: true,
      title:{
        text: "Personalidade"
      },
      axisY : {
        title: "Pontuação"
      },
      data: [{
        type: "column",
        dataPoints: this.data,
      }]
    });
    chart.render();
  }

}
