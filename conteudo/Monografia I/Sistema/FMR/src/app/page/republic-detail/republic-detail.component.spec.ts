import { async, ComponentFixture, TestBed } from '@angular/core/testing';

import { RepublicDetailComponent } from './republic-detail.component';

describe('RepublicDetailComponent', () => {
  let component: RepublicDetailComponent;
  let fixture: ComponentFixture<RepublicDetailComponent>;

  beforeEach(async(() => {
    TestBed.configureTestingModule({
      declarations: [ RepublicDetailComponent ]
    })
    .compileComponents();
  }));

  beforeEach(() => {
    fixture = TestBed.createComponent(RepublicDetailComponent);
    component = fixture.componentInstance;
    fixture.detectChanges();
  });

  it('should create', () => {
    expect(component).toBeTruthy();
  });
});
