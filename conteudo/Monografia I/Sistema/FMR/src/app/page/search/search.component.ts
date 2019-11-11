import { Component, OnInit } from '@angular/core';
import { ActivatedRoute } from '@angular/router';
import { RepublicaService } from 'src/app/service/republica.service';
import { UserService } from 'src/app/service/user.service';

@Component({
  selector: 'app-search',
  templateUrl: './search.component.html',
  styleUrls: ['./search.component.css']
})
export class SearchComponent implements OnInit {

  q: any = {};
  cidade = '';
  reps: any = [];
  me : any = null;

  constructor(private router: ActivatedRoute, 
              private _repService : RepublicaService,
              private _userService : UserService) { 
    this.router.queryParams.subscribe(params => {
      this.q.cidade = params['cidade'];
      this.q.carater = params['carater'];
      this.cidade = this.q.cidade;
    })
  }

  ngOnInit() {
      this.loadMe();
      this.loadReps();
  }

  loadMe() {
    this._userService.me().subscribe((data: any) => {
      this.me = data.perfil.personalidade;
    })
  }

  loadReps() {
    this._repService.findBySearch(this.q).subscribe(data => {
      this.reps = data;
    }, err => {
      //alert(err.error.message);
    });
  }

  sumPersonalidade(person) {
    return (person.abertura + person.concordancia + person.consciencia + person.extroversao + person.neuroticismo);
  }

  calculaPorcentagem(rep, me) {
    if (rep.distanciaGeral >= this.sumPersonalidade(me))
      return Math.round((1 - this.sumPersonalidade(me) / rep.distanciaGeral) * 100);

    return Math.round((1 - rep.distanciaGeral / this.sumPersonalidade(me)) * 100);
  }

  search($event) {
    $event.preventDefault();
    this._repService.findBySearch(this.q).subscribe(data => {
      this.reps = data;
    }, err => {
      alert(err.error.message);
    });
  }
}
